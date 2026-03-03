BUREAUCRAT_SRC = main.cpp Bureaucrat.cpp AForm.cpp  Intern.cpp\
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp 

BUREAUCRAT_OBJ = $(BUREAUCRAT_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Bureaucrat

all: $(NAME)

$(NAME): $(BUREAUCRAT_OBJ)
	$(CXX) $(BUREAUCRAT_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUREAUCRAT_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re