/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:35:07 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 13:37:54 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_op *op)
{
	op->len = 0;
	op->plus = 0;
	op->minus = 0;
	op->space = 0;
	op->hash = 0;
	op->zero = 0;
	op->width = -1;
	op->dot = 0;
	op->pre = -1;
	op->length = 0;
	op->type = '0';
}

void	validity(const char *restrict format, int len, t_op *op)
{
	int		i;
	int		u;
	int		z;
	char	*valid;

	len = len - 1;
	i = 0;
	valid = "0123456789 -+#.hljz";
	while (i < len)
	{
		u = 0;
		z = 0;
		while (valid[u] != '\0')
		{
			if (format[i] == valid[u])
				z++;
			u++;
		}
		if (z != 1)
		{
			op->type = '0';
			break ;
		}
		i++;
	}
}

void	type_and_len(const char *restrict format, t_op *op)
{
	int		i;
	int		u;
	char	*type;

	i = 0;
	type = "sSpdDioOuUxXcC%";
	format++;
	while (format[i] && op->type == '0')
	{
		u = 0;
		while (type[u])
		{
			if (format[i] == type[u])
				op->type = type[u];
			u++;
		}
		i++;
	}
	validity(format, i, op);
	op->len = i;
}
