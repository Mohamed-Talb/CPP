PMERGEME_SRC = main.cpp PmergeMe.cpp

PMERGEME_OBJ = $(PMERGEME_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = PmergeMe

all: $(NAME)

$(NAME): $(PMERGEME_OBJ)
	$(CXX) $(PMERGEME_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(PMERGEME_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re