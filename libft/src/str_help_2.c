/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:22:54 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/18 14:20:46 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*max_sp_z_right(char *str, int nbr, int min)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	min = -min;
	len = (min > nbr) ? min : nbr;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (str[0] == '-' || str[0] == '+')
		new[i++] = (str[0] == '-') ? '-' : '+';
	if (str[0] == ' ')
		new[i++] = ' ';
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		str++;
	while (i <= nbr - (int)ft_strlen(str))
		new[i++] = '0';
	while (*str != '\0')
		new[i++] = *str++;
	while (i < min)
		new[i++] = ' ';
	new[i] = '\0';
	return (new);
}

char	*max_sp_z_left(char *str, int nbr, int min)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = (min > nbr) ? min : nbr;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len - nbr)
		new[i++] = ' ';
	if (i == 0 && (str[0] == '-' || str[0] == '+' || str[0] == ' '))
		i++;
	if (str[0] == '-' || str[0] == '+')
		new[i - 1] = (str[0] == '-') ? '-' : '+';
	if (str[0] == ' ')
		new[i - 1] = ' ';
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		str++;
	while (i < len - (int)ft_strlen(str))
		new[i++] = '0';
	while (*str != '\0')
		new[i++] = *str++;
	new[i] = '\0';
	return (new);
}
