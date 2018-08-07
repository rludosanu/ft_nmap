/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:54:17 by aleblanc          #+#    #+#             */
/*   Updated: 2015/11/26 16:57:56 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*begin;

	i = 0;
	begin = b;
	if (b == NULL)
		return (NULL);
	while (i < len)
	{
		begin[i] = c;
		i++;
	}
	return (b);
}
