DIAMONDTRAP_SRC = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp

DIAMONDTRAP_OBJ = $(DIAMONDTRAP_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = DiamondTrap

all: $(NAME)

$(NAME): $(DIAMONDTRAP_OBJ)
	$(CXX) $(DIAMONDTRAP_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIAMONDTRAP_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re