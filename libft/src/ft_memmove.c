/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:29:03 by aleblanc          #+#    #+#             */
/*   Updated: 2015/11/30 16:31:03 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char*) * len)))
		return (NULL);
	tmp = ft_strncpy(tmp, src, len);
	dst = (void*)ft_strncpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
