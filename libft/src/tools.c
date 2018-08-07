/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:27:38 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 10:55:54 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		intlen(int nbr)
{
	int		len;

	len = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	if (nbr >= 0 && nbr < 10)
		len++;
	return (len);
}

int		test_lh(const char *restrict format, char c)
{
	int		i;

	i = 0;
	while (*format)
	{
		if (*format == c)
			i++;
		format++;
	}
	return (i);
}
