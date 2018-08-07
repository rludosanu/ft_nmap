/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:24:08 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/20 13:18:55 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		recur_uitoa_b(unsigned int nb, int base, int index, char *ptr)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned int)base)
	{
		index = recur_uitoa_b(nb / base, base, index, ptr);
		index = recur_uitoa_b(nb % base, base, index, ptr);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char			*ft_uitoa_base(unsigned int nb, int base)
{
	int				index;
	char			*ptr;

	index = 0;
	ptr = ft_strnew(21);
	recur_uitoa_b(nb, base, index, ptr);
	return (ptr);
}
