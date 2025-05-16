NAME = materia

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincs

SRCDIR = srcs

OBJSDIR = objs

SRCS = $(SRCDIR)/main.cpp \
		$(SRCDIR)/AMateria.cpp \
		$(SRCDIR)/Cure.cpp \
		$(SRCDIR)/Ice.cpp \
		$(SRCDIR)/MateriaSource.cpp \
		$(SRCDIR)/Character.cpp \


OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJSDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJSDIR)/main.o\
	rm -f $(OBJSDIR)/AMaterial.o\
	rm -f $(OBJSDIR)/Cure.o\
	rm -f $(OBJSDIR)/Ice.o\
	rm -f $(OBJSDIR)/MateriaSource.o\
	rm -f $(OBJSDIR)/IMateriaSource.o\
	rm -f $(OBJSDIR)/Character.o\
	rm -f $(OBJSDIR)/ICharacter.o\
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run