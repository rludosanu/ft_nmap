/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:45 by aleblanc          #+#    #+#             */
/*   Updated: 2015/12/01 08:36:23 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0')
		index++;
	if (s1[index] == '\0' && s2[index] == '\0')
		return (0);
	if (s1[index] != s2[index])
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
