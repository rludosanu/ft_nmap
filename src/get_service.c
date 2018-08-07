#include "ft_nmap.h"

char  *get_service(int port, const char *proto) {
  struct servent  *s;

  if ((s = getservbyport(htons(port), proto)))
    return (s->s_name);
  else
    return ("Unassigned");
}
