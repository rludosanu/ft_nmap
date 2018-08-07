/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:41:53 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/01 16:25:35 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		st;
	int		e;
	int		tt;

	st = 0;
	e = ft_strlen(s) - 1;
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	tt = e + 1 - st;
	if (tt < 0)
		tt = 0;
	return (ft_strsub(s, st, tt));
}
