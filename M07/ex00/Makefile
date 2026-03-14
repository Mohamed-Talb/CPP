WHATEVER_SRC = main.cpp

WHATEVER_OBJ = $(WHATEVER_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Whatever

all: $(NAME)

$(NAME): $(WHATEVER_OBJ)
	$(CXX) $(WHATEVER_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(WHATEVER_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re