PHONEBOOK_SRC = PhoneBook.cpp Contact.cpp PhoneBookUtils.cpp

PHONEBOOK_OBJ = $(PHONEBOOK_SRC:.cpp=.o)

#COMPILING
CPPC = c++ -g3
FLAGS = -Wall -Wextra -Werror

#OUTPUT
NAME = PhoneBook

all: $(NAME)

$(NAME): $(PHONEBOOK_OBJ)
	$(CPPC) $(PHONEBOOK_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CPPC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(PHONEBOOK_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re