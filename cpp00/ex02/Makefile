# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 12:20:25 by aryamamo          #+#    #+#              #
#    Updated: 2025/04/19 19:57:25 by aryamamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
SRCS = tests.cpp \
		Account.cpp
OBJS = $(SRCS:.cpp=.o)
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

run: $(NAME)
	./$(NAME)



.PHONY: all clean fclean re run