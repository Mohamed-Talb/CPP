Account_SRC = tests.cpp Account.cpp		

Account_OBJ = $(Account_SRC:.cpp=.o)

#COMPILING
CPPC = c++ -g3
# FLAGS = -Wall -Wextra -Werror

#OUTPUT
NAME = Account

all: $(NAME)

$(NAME): $(Account_OBJ)
	$(CPPC) $(Account_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CPPC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(Account_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
