SCAVTRAP_SRC = main.cpp ScavTrap.cpp ClapTrap.cpp

SCAVTRAP_OBJ = $(SCAVTRAP_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = ScavTrap

all: $(NAME)

$(NAME): $(SCAVTRAP_OBJ)
	$(CXX) $(SCAVTRAP_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(SCAVTRAP_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re