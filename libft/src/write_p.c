/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 08:42:32 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/28 11:54:37 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_p(va_list ap, t_op *op)
{
	long long	nbr;
	char		*result;

	nbr = (long long)va_arg(ap, void *);
	result = op_p(nbr, op);
	ft_putstr(result);
	return (ft_strlen(result));
}
