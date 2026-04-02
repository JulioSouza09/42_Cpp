CC 			:= c++
CPPFLAGS 	:= -Wall -Wextra -Werror -std=c++98
ODIR 		:= obj
SRC 		:= main.cpp \
			   Fixed.cpp
NAME 		:= FixedPoint
OBJ 		:= $(patsubst %.cpp, $(ODIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(ODIR)/%.o: %.cpp
	mkdir -p $(ODIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all