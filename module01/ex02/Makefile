NAME=hiThisIsBrain
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g
SRC=main.cpp
OBJ=$(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
