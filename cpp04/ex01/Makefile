
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincs


NAME		= brain


SRCDIR		= srcs
OBJSDIR		= objs
INCDIR		= incs


SRCS		= $(SRCDIR)/main.cpp \
				$(SRCDIR)/Animal.cpp \
				$(SRCDIR)/Brain.cpp \
				$(SRCDIR)/Dog.cpp \
				$(SRCDIR)/Cat.cpp \
				$(SRCDIR)/WrongAnimal.cpp \
				$(SRCDIR)/WrongCat.cpp
OBJS		= $(SRCS:$(SRCDIR)/%.cpp=$(OBJSDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJSDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJSDIR)/main.o\
	rm -f $(OBJSDIR)/Animal.o\
	rm -f $(OBJSDIR)/Brain.o\
	rm -f $(OBJSDIR)/Dog.o\
	rm -f $(OBJSDIR)/Cat.o\
	rm -f $(OBJSDIR)/WrongAnimal.o\
	rm -f $(OBJSDIR)/WrongCat.o\
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run
