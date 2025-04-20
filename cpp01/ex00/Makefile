NAME = zombie
C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re