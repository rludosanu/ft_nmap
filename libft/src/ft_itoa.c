/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:27:36 by aleblanc          #+#    #+#             */
/*   Updated: 2015/11/27 16:07:21 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (ft_strjoin("-", ft_itoa(-n)));
	if (!(c = ft_strdup("0")))
		return (NULL);
	*c = *c + (n % 10);
	if (n >= 0 && n <= 9)
		return (ft_strdup(c));
	else
		return (ft_strjoin(ft_itoa(n / 10), c));
	return (0);
}
