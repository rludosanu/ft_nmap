/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:25:03 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/13 12:35:06 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	char		*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	while (i < n)
	{
		if (srce[i] == c)
			return ((void *)&dest[i + 1]);
		dest[i] = srce[i];
		i++;
	}
	return (NULL);
}
