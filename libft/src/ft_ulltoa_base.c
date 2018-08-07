/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:10:00 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/20 13:00:09 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		recur_ulltoa_b(unsigned long long nb, int base, int index,
								char *ptr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned long long)base)
	{
		index = recur_ulltoa_b(nb / base, base, index, ptr);
		index = recur_ulltoa_b(nb % base, base, index, ptr);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char			*ft_ulltoa_base(unsigned long long nb, int base)
{
	int					index;
	char				*ptr;

	index = 0;
	ptr = ft_strnew(21);
	recur_ulltoa_b(nb, base, index, ptr);
	return (ptr);
}
