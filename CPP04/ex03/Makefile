NAME = Interface
SOURCES = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)

CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = rm -f
CC = c++

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re