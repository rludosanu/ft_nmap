/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:15:34 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/03 12:56:59 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	size_t		i;
	size_t		b;
	wchar_t		*new;

	i = 0;
	b = 0;
	if (ws == NULL)
		return (NULL);
	if ((new = ft_wstrnew(len)))
	{
		while (ws[start] != '\0' && b + bytes_len(ws[start]) <= len)
		{
			new[i] = ws[start];
			b = b + bytes_len(ws[start]);
			start++;
			i++;
		}
	}
	return (new);
}
