FRAGTRAP_SRC = main.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp

FRAGTRAP_OBJ = $(FRAGTRAP_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = FragTrap

all: $(NAME)

$(NAME): $(FRAGTRAP_OBJ)
	$(CXX) $(FRAGTRAP_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(FRAGTRAP_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re