SRCS		= main.cpp \

OBJS		= $(SRCS:.cpp=.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= iter

all: $(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -g

RM		= rm -rf

t: re
	clear
	./iter

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all