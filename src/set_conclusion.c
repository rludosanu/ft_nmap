#include "ft_nmap.h"

void	set_conclusion(t_host *host)
{
	t_report	*r;

	r = host->report;
	while (r != NULL)
	{
		if (r->scan_syn == ST_CLS || \
			r->scan_ack == ST_CLS || \
			r->scan_null == ST_CLS || \
			r->scan_fin == ST_CLS || \
			r->scan_xmas == ST_CLS || \
			r->scan_udp == ST_CLS)
		{
			ft_strncpy(r->state, "Closed", 32);
		}
		else if (r->scan_syn == ST_OPN || \
			r->scan_ack == ST_OPN || \
			r->scan_null == ST_OPN || \
			r->scan_fin == ST_OPN || \
			r->scan_xmas == ST_OPN || \
			r->scan_udp == ST_OPN)
		{
			ft_strncpy(r->state, "Open", 32);
		}
		r = r->next;
	}
}

void	tv_sub(struct timeval *now, struct timeval *past)
{
	if ((now->tv_usec -= past->tv_usec) < 0)
	{
		--now->tv_sec;
		now->tv_usec += 1000000;
	}
	now->tv_sec -= past->tv_sec;
}
