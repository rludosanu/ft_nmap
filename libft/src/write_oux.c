/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:37:52 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:12:51 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_ouxh(va_list ap, t_op *op)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)((unsigned short)va_arg(ap, int));
	return (op_oux(nbr, op));
}

char	*write_ouxhh(va_list ap, t_op *op)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)((unsigned char)va_arg(ap, unsigned int));
	return (op_oux(nbr, op));
}

char	*write_ouxl(va_list ap, t_op *op)
{
	unsigned long long	nbr;

	nbr = (unsigned long long)va_arg(ap, unsigned long);
	return (op_oux(nbr, op));
}

char	*write_ouxll(va_list ap, t_op *op)
{
	unsigned long long	nbr;

	nbr = va_arg(ap, unsigned long long);
	return (op_oux(nbr, op));
}

int		write_oux(va_list ap, t_op *op)
{
	unsigned long long	nbr;
	char				*result;

	if (op->length == 3 || op->length == 6 || op->type == 'O'
			|| op->type == 'U')
		result = write_ouxl(ap, op);
	else if (op->length == 4 || op->length == 5)
		result = write_ouxll(ap, op);
	else if (op->length == 2)
		result = write_ouxh(ap, op);
	else if (op->length == 1)
		result = write_ouxhh(ap, op);
	else
	{
		nbr = (unsigned long long)va_arg(ap, unsigned int);
		result = op_oux(nbr, op);
	}
	if (op->type == 'X')
		ft_strtoupper(result);
	ft_putstr(result);
	return (ft_strlen(result));
}
