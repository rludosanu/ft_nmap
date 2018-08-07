/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_else.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:12:59 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 09:32:52 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_else(char *str, t_op *op)
{
	while (op->width > (int)ft_strlen(str))
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
