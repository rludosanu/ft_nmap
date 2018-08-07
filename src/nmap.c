#include "ft_nmap.h"

extern t_info	info;

int		portnb(void)
{
	int	i;

	i = 0;
	while (info.ports[i] != 0 && i < 1024)
		i++;
	return (i);
}

void	nmap(void)
{
	t_host			*host;
	t_tdata			*tdata;
	struct timeval	start;
	struct timeval	end;
	int				i;
	int				ptt;
	int				rest;
	int				len;
	int				index;
	int				port_nb;

	host = info.dst;

	// Number of ports to scan
	port_nb = portnb();

	// Print scan config
	print_config(info.dst);

	// Set scan start time
	gettimeofday(&start, NULL);

	// For each host in the list
	while (host != NULL)
	{
		i = 0;
		index = 0;
		
		printf("Scanning %s (%s)...\n\n", host->name, host->ip);

		// single-thread
		if (info.thread_max == 0)
		{
			if (info.verbose)
				printf("Using single-thread scan...\n\n");

			// thread data infos
			if ((tdata = (t_tdata *)malloc(sizeof(t_tdata))))
			{
				tdata->host = host;
				tdata->pidx = 0;
				tdata->len = port_nb;

				in_thread(tdata);
			}
		}
		// multi-thread
		else
		{
			if (info.verbose)
				printf("Using multi-threads scan...\n\n");

			// calculate port per thread
			ptt = port_nb / info.thread_max;

			// calculate the rest to dispatch
			rest = port_nb % info.thread_max;

			// if more thread than ports, use only thread do we need
			if (ptt == 0)
			{
				for (int u = 0; u < port_nb; u++)
					create_thread(host, u, 1);
			}
			// distribute ptt port for each thread and dispatch the rest
			else
			{
				while (i < info.thread_max)
				{
					len = i < rest ? ptt + 1 : ptt;
					create_thread(host, index, len);
					index += len;
					i++;
				}
			}

			while (info.thread_num != 0)
				;
		}

	    set_conclusion(host);
	    print_result(host);
		printf("\n");
	    host = host->next;
	}

	gettimeofday(&end, NULL);
	tv_sub(&end, &start);
	printf("Scan done in %d.%d seconds\n", (int)end.tv_sec, (int)end.tv_usec);
}
