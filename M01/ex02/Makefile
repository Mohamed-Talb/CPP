BRAIN_SRC = main.cpp

BRAIN_OBJ = $(BRAIN_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = BRAIN

all: $(NAME)

$(NAME): $(BRAIN_OBJ)
	$(CXX) $(BRAIN_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BRAIN_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re