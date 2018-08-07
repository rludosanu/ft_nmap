/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:54:03 by aleblanc          #+#    #+#             */
/*   Updated: 2016/03/02 08:47:44 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign_or_not(const char *nptr)
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

static int		invisible_or_not(const char nptr)
{
	int u;

	u = 0;
	if (nptr == '\n' || nptr == '\t' || nptr == ' ' || nptr == '\r' ||
			nptr == '\v' || nptr == '\f')
		u++;
	return (u);
}

long long		ft_atoill(const char *nptr)
{
	int			i;
	long long	nbr;
	int			sign;

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
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
