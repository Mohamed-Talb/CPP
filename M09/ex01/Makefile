RPN_SRC = main.cpp RPN.cpp

RPN_OBJ = $(RPN_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = RPN

all: $(NAME)

$(NAME): $(RPN_OBJ)
	$(CXX) $(RPN_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(RPN_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re