REPLACE_SRC = main.cpp

REPLACE_OBJ = $(REPLACE_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Replace

all: $(NAME)

$(NAME): $(REPLACE_OBJ)
	$(CXX) $(REPLACE_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(REPLACE_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re