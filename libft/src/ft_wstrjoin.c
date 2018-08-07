/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:02:21 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/28 13:32:55 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrjoin(wchar_t *ws1, wchar_t *ws2)
{
	wchar_t		*new;
	int			i;
	int			i2;
	int			len1;
	int			len2;

	i = 0;
	len1 = ft_wstrlen(ws1);
	len2 = ft_wstrlen(ws2);
	if (!(new = (wchar_t *)malloc(sizeof(wchar_t) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		new[i] = ws1[i];
		i++;
	}
	i2 = 0;
	while (i < len1 + len2)
	{
		new[i] = ws2[i2];
		i++;
		i2++;
	}
	new[i] = '\0';
	return (new);
}
