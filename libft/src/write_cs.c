/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:19:50 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:12:03 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_c_help(t_op *op, char *result, char c)
{
	if (op->minus == 1 && c == 0)
	{
		ft_putchar(0);
		ft_putstr(++result);
		return (ft_strlen(result) + 1);
	}
	else if (op->minus == 0 && c == 0)
	{
		ft_putstr(++result);
		ft_putchar(0);
		return (ft_strlen(result) + 1);
	}
	else
	{
		ft_putstr(result);
		return (ft_strlen(result));
	}
}

int		write_c(va_list ap, t_op *op)
{
	char	c;
	char	*result;

	c = (char)va_arg(ap, int);
	if (c == 0)
		result = op_cs("\0", op);
	else
	{
		result = ft_strnew(1);
		result[0] = c;
		result = op_cs(result, op);
	}
	return (write_c_help(op, result, c));
}

int		write_cs(va_list ap, t_op *op)
{
	char	*result;
	int		len;

	if (op->length == 3)
		return (write_csmaj(ap, op));
	else if (op->type == 'c')
		len = write_c(ap, op);
	else
	{
		result = va_arg(ap, char *);
		if (result == NULL)
		{
			result = ft_strnew(7);
			result = "(null)";
		}
		result = op_cs(result, op);
		ft_putstr(result);
		len = ft_strlen(result);
	}
	return (len);
}
