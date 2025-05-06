NAME = Fixed

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -f

SRC	=	main.cpp		Fixed.cpp		Point.cpp		bsp.cpp

SRC_OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.cpp Fixed.hpp Point.hpp
	$(CC) $(FLAGS) -c $<

re: fclean all

.PHONY:			clean