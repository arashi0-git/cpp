NAME = zombiehorde
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

HEADER = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADER)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run