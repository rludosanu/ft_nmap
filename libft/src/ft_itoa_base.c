/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:24:08 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 12:55:40 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		recur_itoa_b(unsigned int nb, int base, int index, char *ptr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned int)base)
	{
		index = recur_itoa_b(nb / base, base, index, ptr);
		index = recur_itoa_b(nb % base, base, index, ptr);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char			*ft_itoa_base(int nb, int base)
{
	unsigned int	i;
	int				index;
	char			*ptr;

	i = nb;
	index = 0;
	ptr = ft_strnew(20);
	if (nb < 0 && base == 10)
	{
		ptr[index++] = '-';
		i = -nb;
	}
	recur_itoa_b(i, base, index, ptr);
	return (ptr);
}
