NAME = megaphone
SOURCES = megaphone.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = c++

all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
