/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:25:14 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/05 09:17:53 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
