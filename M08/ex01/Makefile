SPAN_SRC = main.cpp Span.cpp

SPAN_OBJ = $(SPAN_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Span

all: $(NAME)

$(NAME): $(SPAN_OBJ)
	$(CXX) $(SPAN_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(SPAN_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re