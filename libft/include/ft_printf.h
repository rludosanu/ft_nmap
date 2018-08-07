/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:48:44 by aleblanc          #+#    #+#             */
/*   Updated: 2016/02/04 10:56:15 by aleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_op
{
	int			len;
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
	int			width;
	int			dot;
	int			pre;
	int			length;
	char		type;
}				t_op;

int				ft_printf(const char *restrict format, ...);
int				ft_printf_help(va_list ap, t_op *op);
t_op			*detect(const char *restrict format);
void			init_struct(t_op *op);
void			validity(const char *restrict format, int len, t_op *op);
void			type_and_len(const char *restrict format, t_op *op);
void			detect_help1(const char *restrict format, t_op *op, int i);
void			detect_help2(const char *restrict format, t_op *op, int i);
void			detect_length(const char *restrict format, t_op *op);
int				write_cs(va_list ap, t_op *op);
int				write_c(va_list ap, t_op *op);
int				write_c_help(t_op *op, char *result, char c);
int				write_csmaj(va_list ap, t_op *op);
int				write_cmaj(va_list ap, t_op *op);
int				write_cmaj_help(t_op *op, wchar_t *result, wchar_t c);
int				write_id(va_list ap, t_op *op);
char			*write_idh(va_list ap, t_op *op);
char			*write_idhh(va_list ap, t_op *op);
char			*write_idl(va_list ap, t_op *op);
char			*write_idll(va_list ap, t_op *op);
char			*write_idz(va_list ap, t_op *op);
int				write_oux(va_list ap, t_op *op);
char			*write_ouxh(va_list ap, t_op *op);
char			*write_ouxhh(va_list ap, t_op *op);
char			*write_ouxl(va_list ap, t_op *op);
char			*write_ouxll(va_list ap, t_op *op);
int				write_p(va_list ap, t_op *op);
int				write_per(t_op *op);
int				write_else(const char *restrict format, t_op *op);
char			*op_cs(char *str, t_op *op);
wchar_t			*op_csmaj(wchar_t *str, t_op *op);
char			*op_id(long long nbr, t_op *op);
char			*op_oux(unsigned long long nbr, t_op *op);
char			*op_p(long long nbr, t_op *op);
char			*op_per(char *str, t_op *op);
char			*op_else(char *str, t_op *op);
int				intlen(int nbr);
int				test_lh(const char *restrict format, char c);
int				ft_putwchar(wchar_t c);
int				ft_putwstr(wchar_t *wstr);
wchar_t			*ft_wstrnew(size_t size);
wchar_t			*ft_wstrjoin(wchar_t *ws1, wchar_t *ws2);
wchar_t			*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
size_t			ft_wstrlen(wchar_t *ws);
int				bytes_len(wchar_t s);
int				bytes_len_str(wchar_t *ws);
void			ft_strtoupper(char *ptr);
int				ft_atoi_base(const char *str, int base);
char			*ft_uitoa_base(unsigned int n, int base);
char			*ft_lltoa(long long int n);
char			*ft_lltoa_base(long long int n, int base);
char			*ft_ulltoa_base(unsigned long long int n, int base);
#endif
