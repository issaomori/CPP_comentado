NAME = Intern

SRCS=	main.cpp\
		AForm.cpp\
		Bureaucrat.cpp\
		Form.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		Intern.cpp\
		ShrubberyCreationForm.cpp

OBJS=	$(SRCS:.cpp=.o)

RM=		rm -rf

CC=	c++
FLAGS =		-Wall -Werror -Wextra -std=c++98 -pedantic-errors

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
