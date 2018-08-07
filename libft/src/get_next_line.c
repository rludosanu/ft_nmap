/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:09:25 by aleblanc          #+#    #+#             */
/*   Updated: 2016/04/20 10:58:21 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(t_line *lst)
{
	int	ret;

	if (!(lst->rest = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = read(lst->fd, lst->rest, BUFF_SIZE)) < 0)
		return (ret);
	lst->rest[ret] = '\0';
	lst->ret = ret;
	return (1);
}

t_line	*search_lst(int const fd, t_line **lst)
{
	t_line	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			if (fd == 0 && tmp->rest[0] == '\0')
				read_line(tmp);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_line	*create_lst(int const fd, t_line **lst)
{
	t_line *new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->ret = -1;
	if (read_line(new) < 0)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (*lst);
}

int		line_len(char *rest)
{
	int i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static t_line	*lst = NULL;
	char			*ptr;
	t_line			*tmp;
	short int		i;

	i = 0;
	if (line == NULL || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	while ((tmp = search_lst(fd, &lst)) == NULL)
		if ((lst = create_lst(fd, &lst)) == NULL)
			return (-1);
	*line = "\0";
	while ((ptr = ft_strchr(tmp->rest, '\n')) == NULL && RET != 0 && RET != -2)
		if ((*line = ft_strjoin(*line, tmp->rest)) && ++i > 0)
			read_line(tmp);
	if (ptr && ++i > 0)
		*line = ft_strjoin(*line, ft_strsub(tmp->rest, 0, line_len(tmp->rest)));
	if ((ptr && ptr[1] != '\0') || (ptr && fd == 0))
		tmp->rest = &ptr[1];
	else if (ptr && fd != 0)
		read_line(tmp);
	if (i > 0)
		return (1);
	tmp->ret = -2;
	return (0);
}
