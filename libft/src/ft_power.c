/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:01:06 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/02 12:11:52 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int p;

	if (power == 0)
		p = 1;
	else if (power == 1)
		p = nb;
	else
		p = nb * ft_power(nb, power - 1);
	return (p);
}
