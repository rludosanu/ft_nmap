/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:26:42 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 09:39:51 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		correct_else(const char *restrict format, int i)
{
	if (format[i] && (format[i] == ' ' || (format[i] >= '0' && format[i] <= '9')
				|| format[i] == '-' || format[i] == '.' || format[i] == '#'
				|| format[i] == 'l' || format[i] == 'h' || format[i] == 'z'
				|| format[i] == 'j'))
		return (1);
	return (0);
}

int				write_else(const char *restrict format, t_op *op)
{
	int		i;
	char	*str;

	i = 0;
	format++;
	if (*format)
	{
		while (correct_else(format, i) == 1)
			i++;
		if (format[i])
		{
			str = ft_strsub(format, i, 1);
			str = op_else(str, op);
			ft_putstr(str);
			op->len = i + 1;
			return (ft_strlen(str));
		}
		else
		{
			op->len = i;
			return (0);
		}
	}
	op->len = 0;
	return (0);
}
