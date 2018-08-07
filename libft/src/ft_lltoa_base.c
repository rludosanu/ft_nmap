/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:10:00 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 11:45:55 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		recur_lltoa_b(unsigned long long nb, int base, int index,
								char *ptr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned long long)base)
	{
		index = recur_lltoa_b(nb / base, base, index, ptr);
		index = recur_lltoa_b(nb % base, base, index, ptr);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char			*ft_lltoa_base(long long nb, int base)
{
	unsigned long long	i;
	int					index;
	char				*ptr;

	i = nb;
	index = 0;
	ptr = ft_strnew(21);
	if (nb < 0 && base == 10)
	{
		ptr[index++] = '-';
		i = -nb;
	}
	recur_lltoa_b(i, base, index, ptr);
	return (ptr);
}
