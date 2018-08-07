#ifndef FT_NMAP_H
# define FT_NMAP_H
# include "libft.h"
# include <stdio.h> // printf fopen
# include <netdb.h> // gethostbyname
# include <arpa/inet.h> // inet_ntoa
# include <netinet/ip.h> // ip header
# include <netinet/tcp.h> // tcp header
# include <netinet/udp.h> // udp header
# include <pcap.h> // pcap
# include <pthread.h> // thread
# include <ifaddrs.h> // getifaddrs
# include <netinet/ip_icmp.h>

#include <errno.h>


#define SCAN_SYN      0x1
#define SCAN_NULL     0x2
#define SCAN_FIN      0x4
#define SCAN_XMAS     0x8
#define SCAN_UDP      0x10
#define SCAN_ACK      0x20
#define SCAN_ALL      (SCAN_SYN|SCAN_NULL|SCAN_FIN|SCAN_XMAS|SCAN_UDP|SCAN_ACK)


/* Port scan status */
# define ST_OPN       1 /* Open */
# define ST_CLS       2 /* Closed */
# define ST_FLT       3 /* Filtered */
# define ST_UFLT      4 /* Unfiltered */
# define ST_OFLT      5 /* Open|Filtered */
# define ST_CFLT      6 /* Closed|Filtered */

/* Maximum size in bytes of an ipv4 dot-notation address */
# define HOST_IPV4_SIZE   16

/* Maximum size in bytes of a target hostname */
# define HOST_NAME_SIZE   512


struct                pshdr
{
  unsigned int        src_addr;
  unsigned int        dst_addr;
  unsigned char       placeholder;
  unsigned char       proto;
  unsigned short      tcplen;
  struct tcphdr       tcph;
};

typedef struct        s_report {
  int                 port;       /* Portionst number */
  char                service[128];   /* Service name running in port */
  char                state[32];
  int                 scan_syn;   /* TCP SYN scan status */
  int                 scan_ack;   /* TCP ACTIONK scan status */
  int                 scan_null;  /* TCP NULL scan status */
  int                 scan_fin;   /* TCP FIN scan status */
  int                 scan_xmas;  /* TCP XMAS scan status */
  int                 scan_udp;   /* UDP scan status */
  struct s_report     *next;      /* Next port report */
}                     t_report;

typedef struct        s_host {
  char                name[HOST_NAME_SIZE];
  char                ip[HOST_IPV4_SIZE];
  struct sockaddr_in  *addr;
  t_report            *report;
  struct s_host       *next;
}                     t_host;

typedef struct        s_tdata {
  t_host              *host;
  int                 pidx;
  int                 len;
  pthread_t           id;
}                     t_tdata;

typedef struct        s_pdata {
  t_host              *host;
  int                 port;
  int                 type;
}                     t_pdata;

typedef struct        s_info {
  int                 thread_max;
  int                 thread_num;
  pthread_mutex_t     mutex;
  int                 scans;
  t_host              *src;
  t_host              *dst;
  t_host              *decoy;
  int                 ports[1024];
  int                 verbose; /* Verbose output */
  int                 max_retries; /* Caps number of port scan probe retransmissions */
  int                 scan_delay; /* Adjust delay between probes */
  int                 open; /* Show open ports only */
}                     t_info;

void      nmap(void);
void      print_usage(char *name);
void      print_error(char *error);
char      *check_host(char *host);
t_host    *get_interface(void);

/* Options */
void      init_opt(void);
void      free_opt(void);
void      get_opt(int argc, char **argv);


void      *create_packet(t_host *src, t_host *dst, int port, int type);
int       send_packet(t_host *src, t_host *dst, int sock, int port, int type);
void      create_thread(t_host *host, int pidx, int len);
void      *in_thread(void *handler);
int	      scan(t_host *host, int port, int type);

void      no_response(t_host *host, int port, int type);
void      tcp_response(struct tcphdr *tcp, t_host *host, int port, int type);
void      udp_response(struct udphdr *udp, t_host *host, int port, int type);
void      icmp_response(struct icmphdr *icmp, t_host *host, int port, int type);

t_host    *host_new(const char *name);
t_host    *get_host(t_host *host);
void      host_add(t_host **head, t_host *node);
void      host_lfree(t_host *head);
void      host_free(t_host *node);

char      *get_service(int port, const char *proto);
int       portnb(void);

void      tv_sub(struct timeval *now, struct timeval *past);
void      set_conclusion(t_host *host);
void      print_config(t_host *host);
void      print_result(t_host *host);

/*
** Reporting
*/

t_report	*report_new(int port);
void		report_insert(t_report **head, t_report *report);
t_report	*report_find(t_host *host, int port);
void		report_lfree(t_report *report);

#endif
