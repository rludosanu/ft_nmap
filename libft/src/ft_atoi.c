/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:54:03 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/13 12:49:09 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_or_not(const char *nptr)
{
	int u;
	int i;

	u = 0;
	i = 0;
	while (ft_isdigit(nptr[i]) == 0)
	{
		if (nptr[i] == '+' || nptr[i] == '-')
			u++;
		i++;
	}
	return (u);
}

static int	invisible_or_not(const char nptr)
{
	int u;

	u = 0;
	if (nptr == '\n')
		u++;
	if (nptr == '\t')
		u++;
	if (nptr == ' ')
		u++;
	if (nptr == '\r')
		u++;
	if (nptr == '\v')
		u++;
	if (nptr == '\f')
		u++;
	return (u);
}

int			ft_atoi(const char *nptr)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (invisible_or_not(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	if (nptr[i] == '-' && sign_or_not(nptr) == 1)
	{
		sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
