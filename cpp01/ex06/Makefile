NAME = harlFilter
C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f
all: $(NAME)
$(NAME): $(OBJS)
	$(C++) $(CFLAGS) -o $(NAME) $(OBJS)
%.o: %.cpp
	$(C++) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re