NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

LIBFT_LIB = includes/libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_LIB) $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(PRINTF_LIB) $(LIBFT_LIB)


$(LIBFT_LIB):
	make -C includes/libft

$(NAME_SERVER): $(SRCS_SERVER) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER) $(LIBFT_LIB)

$(NAME_CLIENT): $(SRCS_CLIENT) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT_LIB)

clean:
	make -C includes/libft clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean
	make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re