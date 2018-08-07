/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_oux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:13:35 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 09:29:45 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		op_oux_help2(t_op *op, char *str)
{
	int		i;
	int		len;

	len = op->width - ft_strlen(str);
	i = (len >= 2) ? 2 : 0;
	if (len == 1)
		i = 1;
	return (i);
}

static char		*op_oux_help(char *str, t_op *op, unsigned long long nbr)
{
	char	*sz;
	int		i;

	sz = (op->dot == 0 && op->zero == 1 && op->minus == 0) ? "0" : " ";
	i = (op->pre > 1 && op->hash == 1) ? 1 : 0;
	if (op->hash == 1 && sz[0] == ' ')
	{
		if ((op->type == 'o' || op->type == 'O') && (nbr > 0 || op->pre == 0))
			str = ft_strjoin("0", &str[i]);
		else if ((op->type == 'x' || op->type == 'X') && nbr > 0)
			str = ft_strjoin("0x", str);
	}
	i = op_oux_help2(op, str);
	while (op->width > (int)ft_strlen(str))
	{
		if (op->minus == 1)
			str = ft_strjoin(str, " ");
		else
			str = ft_strjoin(sz, str);
	}
	if (op->hash == 1 && sz[0] == '0')
		if ((op->type == 'x' || op->type == 'X') && nbr > 0)
			str = ft_strjoin("0x", &str[i]);
	return (str);
}

char			*op_oux(unsigned long long nbr, t_op *op)
{
	char	*str;

	str = NULL;
	if (op->type == 'o' || op->type == 'O')
		str = ft_ulltoa_base(nbr, 8);
	else if (op->type == 'u' || op->type == 'U')
		str = ft_ulltoa_base(nbr, 10);
	else if (op->type == 'x' || op->type == 'X')
		str = ft_ulltoa_base(nbr, 16);
	if (op->dot == 1 && op->pre == 0 && nbr == 0)
		str[0] = '\0';
	while (op->pre > (int)ft_strlen(str))
		str = ft_strjoin("0", str);
	str = op_oux_help(str, op, nbr);
	return (str);
}
