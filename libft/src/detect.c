/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:03:04 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 10:55:30 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	detect_help1(const char *restrict format, t_op *op, int i)
{
	while (i++ < op->len - 1)
	{
		if (format[i] >= '1' && format[i] <= '9' && op->dot == 0)
		{
			op->width = ft_atoi(&format[i]);
			i = i + intlen(op->width);
		}
		if (format[i] == '.' || (op->pre == 0 && op->dot == 1))
		{
			op->dot = 1;
			op->pre = ft_atoi(&format[i + 1]);
			if (op->pre < 0)
			{
				op->width = -op->pre;
				op->pre = -1;
			}
		}
		detect_help2(format, op, i);
	}
}

void	detect_help2(const char *restrict format, t_op *op, int i)
{
	if (format[i] == '0')
		op->zero = 1;
	if (format[i] == ' ')
		op->space = 1;
	if (format[i] == '+')
		op->plus = 1;
	if (format[i] == '#')
		op->hash = 1;
	if (format[i] == '-')
		op->minus = 1;
}

void	detect_lenght(const char *restrict format, t_op *op)
{
	format = ft_strsub(format, 0, op->len);
	if (ft_strchr(format, 'h') != NULL)
		op->length = (test_lh(format, 'h') % 2 == 0) ? 1 : 2;
	if (ft_strchr(format, 'l') != NULL)
		op->length = (test_lh(format, 'l') % 2 == 0) ? 4 : 3;
	if (ft_strchr(format, 'j') != NULL)
		op->length = 5;
	if (ft_strchr(format, 'z') != NULL)
		op->length = 6;
}

t_op	*detect(const char *restrict format)
{
	t_op	*op;
	int		i;

	i = -1;
	if (!(op = (t_op *)malloc(sizeof(t_op))))
		return (NULL);
	init_struct(op);
	type_and_len(format, op);
	detect_help1(format, op, i);
	detect_lenght(format, op);
	return (op);
}
