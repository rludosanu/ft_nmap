/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:32:33 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/29 10:22:05 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*op_p(long long nbr, t_op *op)
{
	char *str;

	str = ft_lltoa_base(nbr, 16);
	if (nbr != 0 || (nbr == 0 && op->dot == 0))
		str = ft_strjoin("0x", str);
	else
		str = ft_strjoin("0x", "");
	while (op->pre + 2 > (int)ft_strlen(str))
		str = ft_strjoin(ft_strjoin("0x", "0"), &str[2]);
	while (op->width > (int)ft_strlen(str))
	{
		if (op->minus == 1)
			str = ft_strjoin(str, " ");
		else
		{
			if (op->zero == 1)
				str = ft_strjoin(ft_strjoin("0x", "0"), &str[2]);
			else
				str = ft_strjoin(" ", str);
		}
	}
	return (str);
}
