#include "ft_nmap.h"

void		host_lfree(t_host *head)
{
	t_host	*tmp;
	t_host	*next;

	if (!head)
		return;

	tmp = head;
	while (tmp->next)
	{
		next = tmp->next;
		host_free(tmp);
		tmp = next;
	}
	if (tmp)
	{
		host_free(tmp);
		tmp = NULL;
	}
}

void		host_free(t_host *node)
{
	if (!node)
		return ;

	if (node->addr != NULL)
	{
		free(node->addr);
		node->addr = NULL;
	}

	if (node->report != NULL)
	{
		report_lfree(node->report);
		node->report = NULL;
	}

	free(node);
	node = NULL;
}

void		host_add(t_host **head, t_host *node)
{
	t_host	*tmp;

	if (!*head)
	{
		*head = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_host		*host_new(const char *name)
{
	t_host		*host;

	if (!name)
	{
		printf("Error: Unable to create host: missing target\n");
		return (NULL);
	}

	if (!(host = (t_host *)malloc(sizeof(t_host))))
	{
		printf("Error: Unable to malloc new host\n");
		return (NULL);
	}

	if (!(host->addr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in))))
	{
		printf("Error: Unable to malloc new host\n");
		free(host);
		return (NULL);
	}

	ft_memset(&(host->name), 0, HOST_NAME_SIZE);
	ft_strcpy((char *)&(host->name), name);

	host->report = NULL;
	host->next = NULL;

	return (host);
}

t_host		*get_host(t_host *host)
{
	char				*ip;
	struct hostent		*host_ent;
	struct in_addr		**addr_list;

	host_ent = NULL;
	addr_list = NULL;

	if (!host)
		return (NULL);

	if (!(host_ent = gethostbyname(host->name)))
	{
		printf("Error: Unable to resolve %s\n", host->name);
		host_free(host);
		return (NULL);
	}

	addr_list = (struct in_addr **)host_ent->h_addr_list;
	if ((ip = inet_ntoa(*addr_list[0])))
	{
		// Copy ipv4 addr
		ft_memset((char *)&(host->ip), 0, HOST_IPV4_SIZE);
		ft_strcpy((char *)&(host->ip), ip);

		// Copy sockaddr infos
		host->addr->sin_family = AF_INET;
		host->addr->sin_port = htons(0);
		ft_memset(&(host->addr->sin_zero), 0, 8);
		host->addr->sin_addr.s_addr = inet_addr(ip);
		// inet_pton(AF_INET, ip, (char *)&(host->addr->sin_addr));

		return (host);
	}
	else
		host_free(host);
	
	return (NULL);
}
