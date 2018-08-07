# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 14:01:52 by aleblanc          #+#    #+#              #
#    Updated: 2017/02/14 10:43:08 by aleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INC= -I include

SRC = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c \
	ft_strstr.c ft_strnstr.c ft_atoi.c ft_strcat.c ft_strncat.c 			\
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c 			\
	ft_memchr.c ft_memcmp.c ft_strdup.c ft_strlcat.c ft_strchr.c 			\
	ft_strrchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c 	\
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c 	\
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c 		\
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c 		\
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c		\
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c							\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c					\
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c 							\
	ft_lstmap.c ft_swap.c ft_sqrt.c ft_power.c ft_is_prime.c					\
	ft_isspace.c ft_itoa_base.c ft_atoill.c ft_strisdigit.c						\
	ft_tablen.c																												\
	get_next_line.c																										\
	ft_printf.c detect.c detect_help.c write_cs.c write_csmaj.c				\
	write_id.c write_id_help.c write_oux.c write_p.c write_per.c			\
	write_else.c op_cs.c op_csmaj.c op_id.c op_oux.c op_p.c op_per.c	\
	op_else.c tools.c ft_atoi_base.c ft_uitoa_base.c ft_lltoa.c				\
	ft_lltoa_base.c ft_ulltoa_base.c ft_strtoupper.c ft_putwchar.c		\
	ft_putwstr.c ft_wstrnew.c ft_wstrlen.c ft_wstrjoin.c ft_wstrsub.c ft_arrdel.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): obj $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

obj/%.o: src/%.c
	gcc $(FLAGS) $(INC) -o $@ -c $<

obj:
	mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean
