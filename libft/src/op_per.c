/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_per.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:35:53 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/01 15:38:35 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_per(char *str, t_op *op)
{
	while (op->width > (int)ft_strlen(str))
	{
		if (op->minus == 1)
			str = ft_strjoin(str, " ");
		else if (op->zero == 0)
			str = ft_strjoin(" ", str);
		else
			str = ft_strjoin("0", str);
	}
	return (str);
}
