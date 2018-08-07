/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_id_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:17:39 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:18:25 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_idh(va_list ap, t_op *op)
{
	int	nbr;

	nbr = (long long)((short int)va_arg(ap, int));
	return (op_id(nbr, op));
}

char	*write_idhh(va_list ap, t_op *op)
{
	int	nbr;

	nbr = (long long)((char)va_arg(ap, int));
	return (op_id(nbr, op));
}

char	*write_idl(va_list ap, t_op *op)
{
	long long	nbr;

	nbr = (long long)va_arg(ap, long);
	return (op_id(nbr, op));
}

char	*write_idll(va_list ap, t_op *op)
{
	long long	nbr;

	nbr = va_arg(ap, long long);
	return (op_id(nbr, op));
}

char	*write_idz(va_list ap, t_op *op)
{
	long long	nbr;

	nbr = (long long)va_arg(ap, size_t);
	return (op_id(nbr, op));
}
