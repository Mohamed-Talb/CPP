IDENTIFY_SRC = main.cpp Identify.cpp

IDENTIFY_OBJ = $(IDENTIFY_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Identify

all: $(NAME)

$(NAME): $(IDENTIFY_OBJ)
	$(CXX) $(IDENTIFY_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(IDENTIFY_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re