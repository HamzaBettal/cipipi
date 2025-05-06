NAME = DiamondTrap

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

RM = rm -f

SRC	=	main.cpp		ClapTrap.cpp		ScavTrap.cpp		FragTrap.cpp		DiamondTrap.cpp

SRC_OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	$(CC) $(FLAGS) -c $<

re: fclean all

.PHONY:			clean