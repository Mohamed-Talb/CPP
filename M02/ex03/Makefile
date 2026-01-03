BSP_SRC = main.cpp BSP.cpp Point.cpp bsp.cpp

BSP_OBJ = $(BSP_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = Bsp

all: $(NAME)

$(NAME): $(BSP_OBJ)
	$(CXX) $(BSP_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BSP_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re