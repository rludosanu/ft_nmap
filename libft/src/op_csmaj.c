/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_csmaj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:56:12 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 12:57:35 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			bytes_len(wchar_t s)
{
	unsigned int	wc;
	char			*str;

	wc = s;
	str = ft_uitoa_base(wc, 2);
	if (ft_strlen(str) <= 7)
		return (1);
	else if (ft_strlen(str) <= 11)
		return (2);
	else if (ft_strlen(str) <= 16)
		return (3);
	else
		return (4);
}

int			bytes_len_str(wchar_t *ws)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (ws[i] != '\0')
	{
		nb = nb + bytes_len(ws[i]);
		i++;
	}
	return (nb);
}

wchar_t		*op_csmaj(wchar_t *str, t_op *op)
{
	if (op->dot == 1 && op->pre == 0 && op->type == 'S')
		str = ft_wstrnew(1);
	else if (op->dot == 1 && (op->type == 's' || op->type == 'S'))
		str = ft_wstrsub(str, 0, op->pre);
	while (op->width >= bytes_len_str(str) + 1)
	{
		if (op->minus == 1)
			str = ft_wstrjoin(str, L" ");
		else
		{
			if (op->zero == 1)
				str = ft_wstrjoin(L"0", str);
			else
				str = ft_wstrjoin(L" ", str);
		}
	}
	return (str);
}
