#include "ft_nmap.h"

extern t_info	info;

void	print_config(t_host *host)
{
	t_host	*tmp;

	printf("----- Scan configuration -----\n");
	printf("Sniffing device : %s (%s)\n", (info.src)->name, (info.src)->ip);
	printf("Targets addresses : ");
	tmp = host;
	while (tmp)
	{
		printf("%s (%s)%s", tmp->ip, tmp->name, (tmp->next) ? ", " : "\n");
		tmp = tmp->next;
	}
	printf("No of Ports to scan : %d\n", portnb());
	printf("Scans to be performed :");
	if (info.scans & SCAN_SYN)
		printf(" SYN");
	if (info.scans & SCAN_NULL)
		printf(" NULL");
	if (info.scans & SCAN_FIN)
		printf(" FIN");
	if (info.scans & SCAN_XMAS)
		printf(" XMAS");
	if (info.scans & SCAN_ACK)
		printf(" ACK");
	if (info.scans & SCAN_UDP)
		printf(" UDP");
	printf("\nNo of threads : %d\n", info.thread_max);
	if (info.max_retries != 0)
		printf("No of retransmission retries : %d\n", info.max_retries);
	if (info.max_retries != 0)
		printf("Delay between retransmissions : %d secs\n", info.scan_delay);
	printf("\n");
}

void		print_status(char *scan, int status, char *state, int first)
{
	char	expr[50];

	ft_memset(expr, 0, 50);
	if (status == ST_OPN)
		sprintf(expr, "%s(%s)", scan, "Open");
	else if (status == ST_CLS)
		sprintf(expr, "%s(%s)", scan, "Closed");
	else if (status == ST_FLT)
		sprintf(expr, "%s(%s)", scan, "Filtered");
	else if (status == ST_UFLT)
		sprintf(expr, "%s(%s)", scan, "Unfiltered");
	else if (status == ST_OFLT)
		sprintf(expr, "%s(%s)", scan, "Open|Filtered");
	else if (status == ST_CFLT)
		sprintf(expr, "%s(%s)", scan, "Closed|Filtered");
	if (first > 1)
		printf("%-30s%-30s\n", "", expr);
	else
		printf("%-30s%-20s\n", expr, state);
}

void		print_result(t_host *host)
{
	t_report	*r;
	int			f;

	printf("%-10s%-20s%-30s%-20s\n", "Port", "Service", "Results", "Conclusion");
	printf("--------------------------------------------------------------------------------\n");
	r = host->report;
	while (r)
	{
		f = 0;
    while (r && info.open == 1 && ft_strcmp(r->state, "Open") != 0)
      r = r->next;
    if (r == NULL)
      break ;
		printf("%-10d%-20s", r->port, r->service);
		if (r->scan_syn)
			print_status("SYN", r->scan_syn, r->state, ++f);
		if (r->scan_ack)
			print_status("ACK", r->scan_ack, r->state, ++f);
		if (r->scan_null)
			print_status("NULL", r->scan_null, r->state, ++f);
		if (r->scan_fin)
			print_status("FIN", r->scan_fin, r->state, ++f);
		if (r->scan_xmas)
			print_status("XMAS", r->scan_xmas, r->state, ++f);
		if (r->scan_udp)
			print_status("UDP", r->scan_udp, r->state, ++f);
		r = r->next;
	}
	report_lfree(host->report);
	host->report = NULL;
}
