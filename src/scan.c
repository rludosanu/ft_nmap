#include "ft_nmap.h"

extern t_info	info;

void	sniffpacket(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
	t_pdata			*d;
	struct ip		*ip;
	struct tcphdr	*tcp;
	struct udphdr	*udp;
	struct icmphdr	*icmp;
	int				size_ip;

	d = (t_pdata *)args;

	packet += 14;
	ip = (struct ip *)packet;
	size_ip = ip->ip_hl * 4;

	if (size_ip < 20)
	{
		printf("Warning: header response is not well formated for %s:%d type %d\n", d->host->name, d->port, d->type);
		return ;
	}

	if (ip->ip_p == IPPROTO_TCP && header->caplen >= 14 + sizeof(struct ip) + sizeof(struct tcphdr))
	{
		if (info.verbose)
			printf("TCP response received on port %d\n", d->port);

		tcp = (struct tcphdr *)(packet + size_ip);
		tcp_response(tcp, d->host, d->port, d->type);
	}
	else if (ip->ip_p == IPPROTO_UDP && header->caplen >= 14 + sizeof(struct ip) + sizeof(struct udphdr))
	{
		if (info.verbose)
			printf("UDP response received on port %d\n", d->port);

		udp = (struct udphdr *)(packet + size_ip);
		udp_response(udp, d->host, d->port, d->type);
	}
	else if (ip->ip_p == IPPROTO_ICMP && header->caplen >= 14 + sizeof(struct ip) + sizeof(struct icmphdr))
	{
		if (info.verbose)
			printf("ICMP response received on port %d\n", d->port);

		icmp = (struct icmphdr *)(packet + size_ip);
		icmp_response(icmp, d->host, d->port, d->type);
	}
}

int		scan(t_host *host, int port, int type)
{
	int					sock;
	char				errbuf[PCAP_ERRBUF_SIZE];
	pcap_t				*handle;
	char				filter_exp[1024];
	struct bpf_program	fp;
	bpf_u_int32			mask;
	bpf_u_int32			net;
	int					num_packets = 10;
	t_pdata				pdata;
	t_host				*decoy;
	int					ret;

	// Add the port number to test MAYBE A PROBLEM mutex ?
	host->addr->sin_port = htons(port);

	// Configure filter
	sprintf(filter_exp, "src host %s and src port %d and dst host %s", host->ip, port, (info.src)->ip);

	// data
	pdata.host = host;
	pdata.port = port;
	pdata.type = type;

	// Create a raw socket (no need to set options)
	if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0)
	{
		printf("Error: Unable to create raw socket\n");
		return (-1);
	}

	// Get net/mask infos
	pthread_mutex_lock(&(info.mutex));
	if (pcap_lookupnet((info.src)->name, &net, &mask, errbuf) < 0)
	{
		printf("Error: Unable to get net/mask informations\n");
		return (-1);
	}
	pthread_mutex_unlock(&(info.mutex));

	// Loop on probes
	for (int x = 0 ; x < info.max_retries + 1 ; x++)
	{
		pthread_mutex_lock(&(info.mutex));
		
		// Open device for live capture
		if ((handle = pcap_open_live((info.src)->name, BUFSIZ, 1, info.scan_delay * 1000, errbuf)) == NULL)
		{
			printf("Error: Unable to open %s for live capture: %s\n", (info.src)->name, errbuf);
			return (-1);
		}

		// Compile pcap filter expression
		if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1)
		{
			printf("Error: Unable to compile pcap filter\n");
			pcap_close(handle);
			return (-1);
		}

		// Set pcap filter expression
		if (pcap_setfilter(handle, &fp) == -1)
		{
			printf("Error: Unable to set pcap filter\n");
			pcap_close(handle);
			return (-1);
		}

		// No longer need once pcap_setfilter is called
		pcap_freecode(&fp);

		pthread_mutex_unlock(&(info.mutex));

		// Send valid packet
		send_packet(info.src, host, sock, port, type);
		
		// Send decoy packet(s)
		decoy = info.decoy;
		while (decoy)
		{
			send_packet(decoy, host, sock, port, type);
			decoy = decoy->next;
		}

		// Dispatch incoming packets
		ret = pcap_dispatch(handle, num_packets, sniffpacket, (void *)&pdata);
		if (ret == 0)
		{
			if (info.verbose)
				printf("(%d) No reponse to probe %d on port %d, re-sending...\n", ret, x, port);
			no_response(host, port, type);
		}
		else
		{
			pcap_close(handle);
			break;
		}

		pcap_close(handle);
	}

	close(sock);
	return (0);
}
