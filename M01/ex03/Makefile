WEAPON_SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

WEAPON_OBJ = $(WEAPON_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Weapon

all: $(NAME)

$(NAME): $(WEAPON_OBJ)
	$(CXX) $(WEAPON_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(WEAPON_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re