SCALAR_SRC = main.cpp ScalarConvert.cpp

SCALAR_OBJ = $(SCALAR_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Scalar

all: $(NAME)

$(NAME): $(SCALAR_OBJ)
	$(CXX) $(SCALAR_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(SCALAR_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re