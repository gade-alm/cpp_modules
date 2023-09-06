SRCS		= main.cpp \

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= fixed

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -g

RM		= rm -rf

t: re
	./fixed

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all