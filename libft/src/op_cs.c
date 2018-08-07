/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:33 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/02 15:39:03 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_cs(char *str, t_op *op)
{
	if (op->dot == 1 && op->pre == 0 && op->type == 's')
		str = ft_strnew(1);
	else if (op->dot == 1 && op->type == 's')
		str = ft_strsub(str, 0, op->pre);
	while (op->width > (int)ft_strlen(str) || (op->pre > (int)ft_strlen(str)
				&& op->type == 'c' && op->plus == 1))
	{
		if (op->minus == 1)
			str = ft_strjoin(str, " ");
		else
		{
			if (op->zero == 1)
				str = ft_strjoin("0", str);
			else
				str = ft_strjoin(" ", str);
		}
	}
	return (str);
}
