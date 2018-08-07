/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:44:38 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 12:54:29 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_help(va_list ap, t_op *op)
{
	if (op->type == 'd' || op->type == 'i' || op->type == 'D')
		return (write_id(ap, op));
	else if (op->type == 'o' || op->type == 'O' || op->type == 'u' ||
			op->type == 'U' || op->type == 'x' || op->type == 'X')
		return (write_oux(ap, op));
	else if (op->type == 'c' || op->type == 's')
		return (write_cs(ap, op));
	else if (op->type == 'C' || op->type == 'S')
		return (write_csmaj(ap, op));
	else if (op->type == 'p')
		return (write_p(ap, op));
	else if (op->type == '%')
		return (write_per(op));
	else
		return (-1);
}

int		ft_printf(const char *restrict format, ...)
{
	t_op				*op;
	int					len;
	va_list				ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format && *format != '%')
		{
			ft_putchar(*format++);
			len++;
		}
		else
		{
			op = detect(format);
			if (op->type != '0')
				len = len + ft_printf_help(ap, op);
			else
				len = len + write_else(format, op);
			format = format + op->len + 1;
			free(op);
		}
	}
	return (len);
}
