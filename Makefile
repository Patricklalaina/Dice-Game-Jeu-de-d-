NAME = ludo

SRC = $(wildcard ./src/*.c)

CFLAGS = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME) -lSDL2 -lSDL2_image

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean
