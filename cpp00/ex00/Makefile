SRCS		= megaphone.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME		= megaphone

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

RM		= rm -rf

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:
	fclean all
