/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 08:57:59 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/11 15:18:56 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern char		*g_str;

char	*add_space(char *str, int nbr, int len)
{
	int		i;
	int		u;
	char	*new;

	i = 0;
	u = 0;
	if (!(new = (char*)malloc(sizeof(char) * nbr + 1)))
		return (NULL);
	while (i < nbr - len)
	{
		new[i] = ' ';
		i++;
	}
	while (str[u] != '\0')
	{
		new[i] = str[u];
		i++;
		u++;
	}
	new[i] = '\0';
	return (new);
}

char	*add_space_end(char *str, int nbr)
{
	int		i;
	int		u;
	char	*new;

	i = 0;
	u = 0;
	nbr = -nbr;
	if (!(new = (char*)malloc(sizeof(char) * nbr + 1)))
		return (NULL);
	while (str[u] != '\0')
	{
		new[i] = str[u];
		i++;
		u++;
	}
	while (i < nbr)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*max_sp_right(char *str, int nbr, int min)
{
	int		i;
	int		len;
	char	*new;

	i = -1;
	min = -min;
	if (min > nbr)
		len = min;
	else
		len = nbr;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < nbr)
		new[i] = str[i];
	while (i < min && str[i] != '\0' && min > nbr)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*max_sp_left(char *str, int nbr, int min)
{
	int		i;
	int		u;
	int		len;
	char	*new;

	i = -1;
	u = -1;
	if (min > nbr)
		len = min;
	else
		len = nbr;
	if ((size_t)nbr > ft_strlen(str))
		nbr = ft_strlen(str);
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < min - nbr && min > nbr)
		new[i] = ' ';
	while (++u < nbr)
	{
		new[i] = str[u];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	add_result(const char *restrict src, int len)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	while (g_str[i])
		i++;
	while (u < len)
	{
		g_str[i] = src[u];
		i++;
		u++;
	}
}
