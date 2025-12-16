ZOMBIE_SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

ZOMBIE_OBJ = $(ZOMBIE_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Zombie

all: $(NAME)

$(NAME): $(ZOMBIE_OBJ)
	$(CXX) $(ZOMBIE_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(ZOMBIE_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re