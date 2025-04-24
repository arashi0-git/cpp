NAME = operations
C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
		Fixed.cpp
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
run: all
	./$(NAME)
.PHONY: all clean fclean re run