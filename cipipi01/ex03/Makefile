NAME = program

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC	=	humanB.cpp		humanA.cpp		weapon.cpp		main.cpp

SRC_OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.cpp weapon.hpp humanA.hpp humanB.hpp
	$(CC) $(FLAGS) -c $<

re: fclean all

.PHONY:			clean