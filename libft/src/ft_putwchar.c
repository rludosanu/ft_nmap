/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:44:07 by aleblanc          #+#    #+#             */
/*   Updated: 2016/01/23 11:58:58 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_put2octet(char *binary, int len)
{
	char	*mask[2];
	char	*rest;
	int		len_f;
	int		octet;

	mask[0] = ft_strjoin("11", "0");
	mask[1] = ft_strjoin("10", ft_strsub(&binary[len - 6], 0, 6));
	rest = ft_strsub(binary, 0, len - 6);
	len_f = ft_strlen(rest);
	while (ft_strlen(mask[0]) + len_f < 8)
		mask[0] = ft_strjoin(mask[0], "0");
	mask[0] = ft_strjoin(mask[0], rest);
	octet = ft_atoi_base(mask[0], 2);
	write(1, &octet, 1);
	octet = ft_atoi_base(mask[1], 2);
	write(1, &octet, 1);
}

static void		ft_put3octet(char *binary, int len)
{
	char	*mask[3];
	char	*rest;
	int		len_f;
	int		octet;

	mask[0] = ft_strjoin("111", "0");
	mask[1] = ft_strjoin("10", ft_strsub(&binary[len - 12], 0, 6));
	mask[2] = ft_strjoin("10", ft_strsub(&binary[len - 6], 0, 6));
	rest = ft_strsub(binary, 0, len - 12);
	len_f = ft_strlen(rest);
	while (ft_strlen(mask[0]) + len_f < 8)
		mask[0] = ft_strjoin(mask[0], "0");
	mask[0] = ft_strjoin(mask[0], rest);
	octet = ft_atoi_base(mask[0], 2);
	write(1, &octet, 1);
	octet = ft_atoi_base(mask[1], 2);
	write(1, &octet, 1);
	octet = ft_atoi_base(mask[2], 2);
	write(1, &octet, 1);
}

static void		ft_put4octet_init(char **mask, char *binary, int len)
{
	mask[0] = ft_strjoin("1111", "0");
	mask[1] = ft_strjoin("10", ft_strsub(&binary[len - 18], 0, 6));
	mask[2] = ft_strjoin("10", ft_strsub(&binary[len - 12], 0, 6));
	mask[3] = ft_strjoin("10", ft_strsub(&binary[len - 6], 0, 6));
}

static void		ft_put4octet(char *binary, int len)
{
	char	*mask[4];
	int		o[2];

	ft_put4octet_init(mask, binary, len);
	if (len < 18)
	{
		mask[0] = ft_strjoin(mask[0], "000");
		while (ft_strlen(mask[1]) +
				ft_strlen(ft_strsub(binary, 0, len - 12)) < 8)
			mask[1] = ft_strjoin(mask[1], "0");
		mask[1] = ft_strjoin(mask[1], ft_strsub(binary, 0, len - 12));
	}
	else
	{
		while (ft_strlen(mask[0]) +
				ft_strlen(ft_strsub(binary, 0, len - 18)) < 8)
			mask[0] = ft_strjoin(mask[0], "0");
		mask[0] = ft_strjoin(mask[0], ft_strsub(binary, 0, len - 18));
	}
	o[0] = 0;
	while (o[0] < 4)
	{
		o[1] = ft_atoi_base(mask[o[0]++], 2);
		write(1, &o[1], 1);
	}
}

int				ft_putwchar(wchar_t c)
{
	int		len;
	char	*binary;

	binary = ft_uitoa_base(c, 2);
	len = ft_strlen(binary);
	if (len <= 7)
	{
		ft_putchar(c);
		return (1);
	}
	else if (len <= 11)
	{
		ft_put2octet(binary, len);
		return (2);
	}
	else if (len > 11 && len <= 16)
	{
		ft_put3octet(binary, len);
		return (3);
	}
	else
	{
		ft_put4octet(binary, len);
		return (4);
	}
}
