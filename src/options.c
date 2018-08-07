#include "ft_nmap.h"

extern t_info	info;

/*
** Init options
*/
void    init_opt(void)
{
	info.thread_max = 0;
	info.thread_num = 0;
	info.mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	info.scans = SCAN_ALL;
	info.src = get_interface();
	info.dst = NULL;
	info.decoy = NULL;
	for (int i = 0; i < 1024; i++)
		info.ports[i] = i + 1;
	info.verbose = 0;
	info.max_retries = 0;
	info.scan_delay = 1;
	info.open = 0;
}

/*
** Free options
*/
void	free_opt(void)
{
	if (info.src)
		host_free(info.src);
	if (info.dst)
		host_lfree(info.dst);
	if (info.decoy)
		host_lfree(info.decoy);
}

void    get_opt(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (ft_strcmp("--help", argv[i]) == 0)
		{
			print_usage(argv[0]);
		}
		else if (ft_strcmp("--verbose", argv[i]) == 0)
		{
			info.verbose = 1;
		}
		else if (ft_strcmp("--max-retries", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				if ((info.max_retries = ft_atoi(argv[i])) < 0)
					print_error("Error: The number of probe retransmission must be equal or greater than 0\n");
			}
			else
				print_error("Error: The number of probe retransmission must be equal or greater than 0\n");
		}
		else if (ft_strcmp("--scan-delay", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				if ((info.scan_delay = ft_atoi(argv[i])) < 1)
					print_error("Error: The delay between probes must be equal or greater than 1\n");
			}
			else
				print_error("Error: The delay between probes must be equal or greater than 1\n");
		}
		else if (ft_strcmp("--ports", argv[i]) == 0)
		{
			char	**tab;
			int		first;
			int		last;
			if (i + 1 < argc)
			{
				i++;
				ft_memset(info.ports, 0, sizeof(info.ports));
				if (ft_strchr(argv[i], '-') != NULL)
				{
					if (!(tab = ft_strsplit(argv[i], '-')))
					{
						print_error("Error: Unable to parse ports\n");
					}

					if (ft_tablen(tab) != 2 || !ft_strisdigit(tab[0]) || !ft_strisdigit(tab[1]))
					{
						ft_arrdel(&tab);
						print_error("Error: Port range is not well formated\n");
					}

					first = ft_atoi(tab[0]);
					last = ft_atoi(tab[1]);
					if (first > last)
					{
						ft_arrdel(&tab);
						print_error("Error: Port range is not well formated\n");
					}

					if (first < 1 || last < 1 || first > 65535 || last > 65535)
					{
						ft_arrdel(&tab);
						print_error("Error: Ports can only be included between 1-65535\n");
					}

					if (last - first + 1 > 1024)
					{
						ft_arrdel(&tab);
						print_error("Error: The range of ports may not contain more than 1024 ports\n");
					}

					int i = 0;
					while (first <= last)
					{
						info.ports[i++] = first++;
					}

					ft_arrdel(&tab);
				}
				else
				{
					int u = 0;
					while (i < argc && ft_strisdigit(argv[i]))
					{
						if (u >= 1024)
							print_error("Error: The number of ports is limited to 1024\n");
						info.ports[u++] = ft_atoi(argv[i++]);
					}
					if (u == 0)
						print_error("Error: --ports option required a range or specific single ports\n");
					else
						i--;
				}
			}
			else
				print_error("Error: --ports option required a range or specific single ports\n");
		}
		else if (ft_strcmp("--scans", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				info.scans = 0;
				while (i < argc)
				{
					if (!ft_strcmp(argv[i], "SYN"))
						info.scans |= SCAN_SYN;
					else if (!ft_strcmp(argv[i], "NULL"))
						info.scans |= SCAN_NULL;
					else if (!ft_strcmp(argv[i], "FIN"))
						info.scans |= SCAN_FIN;
					else if (!ft_strcmp(argv[i], "XMAS"))
						info.scans |= SCAN_XMAS;
					else if (!ft_strcmp(argv[i], "ACK"))
						info.scans |= SCAN_ACK;
					else if (!ft_strcmp(argv[i], "UDP"))
						info.scans |= SCAN_UDP;
					else
					{
						i--;
						break;
					}
					i++;
				}
			}
			else
				print_error("Error: --scans option required one or more type of scans\n");
		}
		else if (ft_strcmp("--ip", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				if (ft_strlen(argv[i]) < HOST_NAME_SIZE)
					host_add(&(info.dst), get_host((host_new(argv[i]))));
				else
					print_error("Error: --ip host len is too long");
			}
			else
				print_error("Error: --ip option required an host\n");
		}
		else if (ft_strcmp("--file", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				FILE *fp;
				if ((fp = fopen(argv[i], "r")) != NULL)
				{
					char	*line;
					int		fd = fileno(fp);
					
					while (get_next_line(fd, &line) > 0 && ft_strlen(line) < HOST_NAME_SIZE)
					host_add(&(info.dst), get_host((host_new(line))));
				}
				else
					print_error("Error: Invalid filename\n");
			}
			else
				print_error("Error: --file option required a filename\n");
		}
		else if (ft_strcmp("--decoy", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				if (ft_strlen(argv[i]) < HOST_NAME_SIZE)
					host_add(&(info.decoy), get_host((host_new(argv[i]))));
				else
					print_error("Error: --decoy host len is too long");
			}
			else
				print_error("Error: --decoy option required an host\n");
		}
		else if (ft_strcmp("--speedup", argv[i]) == 0)
		{
			if (i + 1 < argc)
			{
				i++;
				if (ft_strisdigit(argv[i]) && ft_atoi(argv[i]) <= 250)
					info.thread_max = ft_atoi(argv[i]);
				else
					print_error("Error: Number of thread is not well formated\n");
			}
			else
				print_error("Error: --speedup option required a number of thread\n");
		}
    else if (ft_strcmp("--open", argv[i]) == 0)
    {
      info.open = 1;
    }
		else
			print_error("Error: Unrecognized option\n");
	}
}
