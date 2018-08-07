#include "ft_nmap.h"

extern t_info	info;

void    *in_thread(void *handler)
{
	t_tdata		*data;
	int			i;

	if (!handler)
	{
		info.thread_num--;
		return (NULL);
	}

	data = (t_tdata *)handler;
	i = 0;

	// For each port
	while (i < data->len)
	{
		if (info.scans & SCAN_SYN)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_SYN);
		}
		if (info.scans & SCAN_NULL)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_NULL);
		}
		if (info.scans & SCAN_FIN)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_FIN);
		}
		if (info.scans & SCAN_XMAS)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_XMAS);
		}
		if (info.scans & SCAN_UDP)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_UDP);
		}
		if (info.scans & SCAN_ACK)
		{
			scan(data->host, info.ports[i + data->pidx], SCAN_ACK);
		}
		i++;
	}

	info.thread_num--;
	free(data);
	return (NULL);
}

void	create_thread(t_host *host, int pidx, int len)
{
	t_tdata		*data;

	if (!(data = (t_tdata *)malloc(sizeof(t_tdata))))
	{
		printf("Error: Unable to create sniffer thread\n");
		return ;
	}
	data->host = host;
	data->pidx = pidx;
	data->len = len;

	if (info.thread_num < info.thread_max)
	{
		if (pthread_create(&(data->id), NULL, in_thread, data) == 0)
		{
			info.thread_num++;
			if (info.verbose)
				printf("New sniffer thread created (%d/%d)\n", info.thread_num, info.thread_max);
		}
		else
			printf("Error: Unable to create sniffer thread\n");
	}
}
