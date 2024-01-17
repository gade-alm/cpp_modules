SRCS		= main.cpp \
				BitcoinExchange.cpp \

OBJS		= $(SRCS:.cpp=.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= btc

all: $(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) #-fsanitize=address -g

RM		= rm -rf

t: re
	clear
	./$(NAME) data.csv

tv: re
	clear
	valgrind ./$(NAME) data.csv

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all