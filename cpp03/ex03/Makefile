NAME = fragtrap
C++ = c++
# FLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run