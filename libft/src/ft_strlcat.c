/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:09:16 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/01 11:59:22 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l1;
	size_t	l2;

	i = 0;
	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
	if (size == 0 || size - 1 <= l1)
		return (l2 + size);
	while (l1 + i < size - 1)
	{
		dst[l1 + i] = src[i];
		i++;
	}
	dst[l1 + i] = '\0';
	return (l1 + l2);
}
