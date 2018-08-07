/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_csmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:57:55 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:09:08 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_cmaj_help(t_op *op, wchar_t *result, wchar_t c)
{
	int		len;

	if (op->minus == 1 && c == 0)
	{
		ft_putwchar(0);
		return (ft_putwstr(++result) + 1);
	}
	else if (op->minus == 0 && c == 0)
	{
		len = ft_putwstr(++result);
		ft_putwchar(0);
		return (len + 1);
	}
	else
		return (ft_putwstr(result));
}

int		write_cmaj(va_list ap, t_op *op)
{
	wchar_t		c;
	wchar_t		*result;

	c = (wchar_t)va_arg(ap, int);
	if (c == 0)
		result = op_csmaj(L"\0", op);
	else
	{
		result = ft_wstrnew(1);
		result[0] = c;
		result = op_csmaj(result, op);
	}
	return (write_cmaj_help(op, result, c));
}

int		write_csmaj(va_list ap, t_op *op)
{
	wchar_t		*result;
	int			len;

	if (op->type == 'C' || op->type == 'c')
		len = write_cmaj(ap, op);
	else
	{
		result = va_arg(ap, wchar_t *);
		if (result == NULL)
		{
			result = ft_wstrnew(7);
			result = L"(null)";
		}
		result = op_csmaj(result, op);
		len = ft_putwstr(result);
	}
	return (len);
}
