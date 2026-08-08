SERIALIZER_SRC = main.cpp Serializer.cpp

SERIALIZER_OBJ = $(SERIALIZER_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Serializer

all: $(NAME)

$(NAME): $(SERIALIZER_OBJ)
	$(CXX) $(SERIALIZER_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(SERIALIZER_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re