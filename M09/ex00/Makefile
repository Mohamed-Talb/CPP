BTC_SRC = main.cpp BitcoinExchange.cpp

BTC_OBJ = $(BTC_SRC:.cpp=.o)

#COMPILING
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#OUTPUT
NAME = btc

all: $(NAME)

$(NAME): $(BTC_OBJ)
	$(CXX) $(BTC_OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BTC_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re