HARL_SRC = main.cpp Harl.cpp

HARL_OBJ = $(HARL_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Harl

all: $(NAME)

$(NAME): $(HARL_OBJ)
	$(CXX) $(HARL_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(HARL_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re