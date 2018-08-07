/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:34:30 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 09:32:01 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*op_id_help(char *str, t_op *op)
{
	char	*sz;

	sz = (op->dot == 0 && op->zero == 1) ? "0" : " ";
	if (op->space == 1 && str[0] != '-' && str[0] != '+')
		str = ft_strjoin(" ", str);
	while (op->width > (int)ft_strlen(str))
	{
		if (op->minus == 1)
			str = ft_strjoin(str, " ");
		else
		{
			if (str[0] == '+' && sz[0] == '0')
				str = ft_strjoin("+0", &str[1]);
			else if (str[0] == '-' && sz[0] == '0')
				str = ft_strjoin("-0", &str[1]);
			else if (str[0] == ' ' && op->space == 1)
				str = ft_strjoin(ft_strjoin(" ", sz), &str[1]);
			else
				str = ft_strjoin(sz, str);
		}
	}
	return (str);
}

char			*op_id(long long nbr, t_op *op)
{
	char	*str;

	str = ft_lltoa(nbr);
	if (nbr < 0)
		str++;
	if (op->dot == 1 && nbr == 0)
		str[0] = '\0';
	while (op->pre > (int)ft_strlen(str))
		str = ft_strjoin("0", str);
	if (op->plus == 1 && nbr >= 0)
		str = ft_strjoin("+", str);
	else if (nbr < 0)
		str = ft_strjoin("-", str);
	str = op_id_help(str, op);
	return (str);
}
