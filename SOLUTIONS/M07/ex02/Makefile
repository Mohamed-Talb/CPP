ARRAY_SRC = main.cpp

ARRAY_OBJ = $(ARRAY_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Array

all: $(NAME)

$(NAME): $(ARRAY_OBJ)
	$(CXX) $(ARRAY_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(ARRAY_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re