/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:55:55 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/28 13:01:59 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t		*new;

	if ((new = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))) != NULL)
		new[size] = '\0';
	return (new);
}
