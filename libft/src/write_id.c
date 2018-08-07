/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 08:53:14 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:18:35 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_id(va_list ap, t_op *op)
{
	long long	nbr;
	char		*result;

	if (op->length == 3 || op->type == 'D')
		result = write_idl(ap, op);
	else if (op->length == 4 || op->length == 5)
		result = write_idll(ap, op);
	else if (op->length == 6)
		result = write_idz(ap, op);
	else if (op->length == 1)
		result = write_idhh(ap, op);
	else if (op->length == 2)
		result = write_idh(ap, op);
	else
	{
		nbr = (long long)va_arg(ap, int);
		result = op_id(nbr, op);
	}
	ft_putstr(result);
	return (ft_strlen(result));
}
