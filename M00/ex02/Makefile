ACCOUNT_SRC = tests.cpp Account.cpp		

ACCOUNT_OBJ = $(ACCOUNT_SRC:.cpp=.o)

#COMPILING
CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror

#OUTPUT
NAME = ACCOUNT

all: $(NAME)

$(NAME): $(ACCOUNT_OBJ)
	$(CXX) $(ACCOUNT_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(ACCOUNT_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
