#include "ft_nmap.h"

extern

t_host		*get_interface(void)
{
	t_host				      *host;
	char				        *device;
	char			 	        errbuf[PCAP_ERRBUF_SIZE];
	struct ifaddrs	    *ifap;
	struct ifaddrs		  *p;
	struct sockaddr_in	*sa;

	host = NULL;

	// Get default device name
	if ((device = pcap_lookupdev(errbuf)) == NULL)
		return (NULL);

	// Get interface list addresses
	if (getifaddrs(&ifap) == -1)
		return (NULL);

	// Search device informations
	p = ifap;
	while (p)
	{
		// If interface is IPV4 for matching device name
		if (p->ifa_addr->sa_family == AF_INET && strcmp(p->ifa_name, device) == 0)
		{
			sa = (struct sockaddr_in *)p->ifa_addr;
			// Malloc new host
			if (!(host = host_new(p->ifa_name)))
			{
				printf("Error: Unable to store sniffing device informations\n");
				break;
			}

			// Copy ipv4 addr
			ft_memset((char *)&(host->ip), 0, HOST_IPV4_SIZE);
			ft_strcpy((char *)&(host->ip), inet_ntoa(sa->sin_addr));

			// Copy sockaddr infos
			host->addr->sin_family = AF_INET;
			host->addr->sin_port = htons(53);
			ft_memset(&(host->addr->sin_zero), 0, 8);
			ft_memcpy(&(host->addr->sin_addr), &(sa->sin_addr), sizeof(struct in_addr));

			break;
		}
		p = p->ifa_next;
	}
	freeifaddrs(ifap);
	return (host);
}
