/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:08:50 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/01 13:18:19 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < ft_strlen(s1))
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
