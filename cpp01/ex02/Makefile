NAME = brain
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
