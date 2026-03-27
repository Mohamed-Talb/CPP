EASYFIND_SRC = main.cpp

EASYFIND_OBJ = $(EASYFIND_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = EasyFind

all: $(NAME)

$(NAME): $(EASYFIND_OBJ)
	$(CXX) $(EASYFIND_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(EASYFIND_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re