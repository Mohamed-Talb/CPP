PHONEBOOK_SRC = PhoneBook.cpp Contact.cpp PhoneBookUtils.cpp

PHONEBOOK_OBJ = $(PHONEBOOK_SRC:.cpp=.o)

#COMPILING
CXX = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror

#OUTPUT
NAME = PhoneBook

all: $(NAME)

$(NAME): $(PHONEBOOK_OBJ)
	$(CXX) $(PHONEBOOK_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(PHONEBOOK_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re