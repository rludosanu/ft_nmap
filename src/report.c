#include "ft_nmap.h"

extern t_info	info;

t_report	*report_new(int port)
{
	t_report	*r;
	char		*serv;

	if (!(r = (t_report *)malloc(sizeof(t_report))))
		return (NULL);
	r->port = port;
	ft_memset(r->service, '\0', 128);
	if ((serv = get_service(port, NULL)) == NULL)
		ft_strncpy(r->service, "Unassigned", 128);
	else
		ft_strncpy(r->service, serv, 128);
	ft_memset(r->state, '\0', 32);
	ft_strncpy(r->state, "Filtered", 32);
	r->scan_syn = 0;
	r->scan_ack = 0;
	r->scan_null = 0;
	r->scan_fin = 0;
	r->scan_xmas = 0;
	r->scan_udp = 0;
	r->next = NULL;

	return (r);
}

void		report_insert(t_report **head, t_report *report)
{
	t_report	*curr;
	t_report	*next;

	if (!*head)
		*head = report;
	else
	{
		curr = *head;
		if (report->port < curr->port)
		{
			*head = report;
			report->next = curr;
		}
		else
		{
			while (curr)
			{
				if (!curr->next || report->port <= curr->next->port)
				{
					next = curr->next;
					curr->next = report;
					report->next = next;
					return ;
				}
				curr = curr->next;
			}
		}
	}
}

t_report	*report_find(t_host *host, int port)
{
	t_report     *r;

	if (host == NULL)
		return (NULL);
	r = host->report;
	while (r)
	{
		if (r->port == port)
			return (r);
		r = r->next;
	}
	if (!(r = report_new(port)))
		return (NULL);
	report_insert(&(host->report), r);
	return (r);
}

void		report_lfree(t_report *report)
{
	t_report	*curr;
	t_report	*next;

	curr = report;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	no_response(t_host *host, int port, int type)
{
	t_report	*r;

	pthread_mutex_lock(&(info.mutex));

	if (!(r = report_find(host, port)))
	{
		printf("Error: Unable to store EMPTY scan report\n");
		return;
	}
	if (type == SCAN_SYN)
		r->scan_syn = ST_FLT;
	else if (type == SCAN_ACK)
		r->scan_ack = ST_FLT;
	else if (type == SCAN_NULL)
		r->scan_null = ST_OFLT;
	else if (type == SCAN_FIN)
		r->scan_fin = ST_OFLT;
	else if (type == SCAN_XMAS)
		r->scan_xmas = ST_OFLT;
	else if (type == SCAN_UDP)
		r->scan_udp = ST_OFLT;

	pthread_mutex_unlock(&(info.mutex));
}

void	tcp_response(struct tcphdr *tcp, t_host *host, int port, int type)
{
	t_report	*r;

	pthread_mutex_lock(&(info.mutex));

	if (!(r = report_find(host, port)))
	{
		printf("Error: Unable to store TCP scan report\n");
		return ;
	}
	if (type == SCAN_SYN)
	{
		if (tcp->ack == 1 && tcp->syn == 1)
			r->scan_syn = ST_OPN;
		else if (tcp->ack == 1 && tcp->rst == 1)
			r->scan_syn = ST_CLS;
	}
	else if (type == SCAN_ACK && tcp->rst == 1)
		r->scan_ack = ST_UFLT;
	else if (type == SCAN_NULL && tcp->rst == 1)
		r->scan_null = ST_CLS;
	else if (type == SCAN_FIN && tcp->rst == 1)
		r->scan_fin = ST_CLS;
	else if (type == SCAN_XMAS && tcp->rst == 1)
		r->scan_xmas = ST_CLS;
	else if (type == SCAN_UDP)
		printf("Error: Unexpected TCP reply from UDP scan\n");

	pthread_mutex_unlock(&(info.mutex));
}

void	udp_response(struct udphdr *udp, t_host *host, int port, int type)
{
	t_report	*r;

	(void)udp;
	pthread_mutex_lock(&(info.mutex));

	if (!(r = report_find(host, port)))
	{
		printf("Error: Unable to store UDP scan report\n");
		return ;
	}
	if (type == SCAN_UDP)
		r->scan_udp = ST_OPN;
	else
		printf("Error: Unexpected UDP reply from TCP scan\n");

	pthread_mutex_unlock(&(info.mutex));
}

void	icmp_response(struct icmphdr *icmp, t_host *host, int port, int type)
{
	t_report	*r;

	pthread_mutex_lock(&(info.mutex));

	if (!(r = report_find(host, port)))
		return ;
	if (type == SCAN_SYN && icmp->type == 3)
		r->scan_syn = ST_FLT;
	else if (type == SCAN_ACK && icmp->type == 3)
		r->scan_ack = ST_FLT;
	else if (type == SCAN_NULL && icmp->type == 3)
		r->scan_null = ST_FLT;
	else if (type == SCAN_FIN && icmp->type == 3)
		r->scan_fin = ST_FLT;
	else if (type == SCAN_XMAS && icmp->type == 3)
		r->scan_xmas = ST_FLT;
	else if (type == SCAN_UDP && icmp->type == 3 && icmp->code == 3)
		r->scan_udp = ST_CLS;
	else if (type == SCAN_UDP && icmp->type == 3 && icmp->code != 3)
		r->scan_udp = ST_FLT;

	pthread_mutex_unlock(&(info.mutex));
}
