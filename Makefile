NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRV_SRC = server.c
CLT_SRC = client.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRV_SRC)
	$(CC) $(CFLAGS) $(SRV_SRC) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLT_SRC)
	$(CC) $(CFLAGS) $(CLT_SRC) -o $(NAME_CLIENT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
