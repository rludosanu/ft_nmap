NAME = ft_nmap

FLAGS = -Wall -Wextra -Werror

INC = -I include -I libft/include

LIBFT = libft

SRC = main.c \
			nmap.c \
			packet.c \
			options.c \
			thread.c \
			report.c \
			get_interface.c \
			get_service.c \
			host.c \
			print.c \
			set_conclusion.c \
			scan.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): obj $(OBJ)
			make -C $(LIBFT)
			gcc -o $(NAME) $(OBJ) -L$(LIBFT) -lft -lpcap -lpthread

obj/%.o: src/%.c
			gcc $(FLAGS) $(INC) -o $@ -c $<

obj:
			mkdir -p obj

clean:
			make -C $(LIBFT) clean
			rm -rf obj

fclean: clean
			make -C $(LIBFT) fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean
