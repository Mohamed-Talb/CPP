MUTANTSTACK_SRC = main.cpp

MUTANTSTACK_OBJ = $(MUTANTSTACK_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = MutantStack

all: $(NAME)

$(NAME): $(MUTANTSTACK_OBJ)
	$(CXX) $(MUTANTSTACK_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(MUTANTSTACK_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re