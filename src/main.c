#include "ft_nmap.h"

t_info	info;

void	print_usage(char *name)
{
	printf("Usage: %s [options]\n", name);
	printf("  %-15s Display this menu\n", "--help");
	printf("  %-15s Ports to scan (by range: 5-15 or individualy: 1 8)\n", "--ports");
	printf("  %-15s FQDN or IPV4 address to scan (google.fr or 123.456.789.111)\n", "--ip");
	printf("  %-15s File containing a list of FQDN or IPV4 address to scan (max 1024)\n", "--file");
	printf("  %-15s Number of parallel threads to use (max 250)\n", "--speedup");
	printf("  %-15s SYN NULL FIN XMAS ACK UDP\n", "--scans");
	printf("  %-15s Verbose output\n", "--verbose");
	printf("  %-15s Number of port scan probe retransmissions\n", "--max-retries");
	printf("  %-15s Delay between probes in seconds\n", "--scan-delay");
	printf("  %-15s Decoy FQDN or IPV4 address to send from\n", "--decoy");
	printf("  %-15s Show open ports only\n", "--open");
	exit(0);
}

void	print_error(char *error)
{
	printf("%s", error);
	free_opt();
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		print_usage(argv[0]);
	}
	else
	{
		init_opt();

		get_opt(argc, argv);

		if (info.dst == NULL)
			print_error("Error: No targets to scan\n");
		else if (info.scans == 0)
			print_error("Error: No scan specified\n");

		nmap();

		free_opt();
	}
	return (0);
}
