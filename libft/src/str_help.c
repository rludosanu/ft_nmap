/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 08:57:59 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/21 10:25:57 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
