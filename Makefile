NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

PRINTF_LIB = includes/ft_printf/libftprintf.a
LIBFT_LIB = includes/libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(PRINTF_LIB) $(LIBFT_LIB) $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(PRINTF_LIB) $(LIBFT_LIB)

$(PRINTF_LIB):
	make -C includes/ft_printf

$(LIBFT_LIB):
	make -C includes/libft

$(NAME_SERVER): $(SRCS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB) -I includes/ft_printf

$(NAME_CLIENT): $(SRCS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB) -I includes/ft_printf

clean:
	make -C includes/ft_printf clean
	make -C includes/libft clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean
	make -C includes/ft_printf fclean
	make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re