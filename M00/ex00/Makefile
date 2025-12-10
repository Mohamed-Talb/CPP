MEGAPHONE_SRC = megaphone.cpp

MEGAPHONE_OBJ = $(MEGAPHONE_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = megaphone

all: $(NAME)

$(NAME): $(MEGAPHONE_OBJ)
	$(CXX) $(MEGAPHONE_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(MEGAPHONE_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re