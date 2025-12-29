FIXED_SRC = main.cpp Fixed.cpp

FIXED_OBJ = $(FIXED_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Fixed

all: $(NAME)

$(NAME): $(FIXED_OBJ)
	$(CXX) $(FIXED_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(FIXED_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re