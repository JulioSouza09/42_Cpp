NAME=PhoneBook
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g
SRC=PhoneBook.cpp Contact.cpp main.cpp
IDIR=include/
OBJ=$(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -I $(IDIR) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
