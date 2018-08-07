/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:05:41 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/25 13:01:01 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_tab_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			len++;
		}
	}
	return (len);
}

static int		ft_word_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		u;
	int		tab_len;
	char	**tab;

	i = 0;
	u = 0;
	tab = NULL;
	tab_len = ft_tab_len(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	while (i < tab_len)
	{
		while (s[u] == c)
			u++;
		if (s[u] != '\0')
			tab[i] = ft_strsub(s, u, ft_word_len(&s[u], c));
		u = u + ft_word_len(&s[u], c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
