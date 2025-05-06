NAME = interface

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC	=	main.cpp	AMateria.cpp	Cure.cpp	Ice.cpp	MateriaSource.cpp	Character.cpp

SRC_OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

%.o: %.cpp ICharacter.hpp AMateria.hpp Cure.hpp Ice.hpp MateriaSource.hpp Character.hpp
	$(CC) $(FLAGS) -c $<

re: fclean all

.PHONY:			clean