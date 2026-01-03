CLAPTRAP_SRC = main.cpp ClapTrap.cpp

CLAPTRAP_OBJ = $(CLAPTRAP_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = ClapTrap

all: $(NAME)

$(NAME): $(CLAPTRAP_OBJ)
	$(CXX) $(CLAPTRAP_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(CLAPTRAP_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re