SRCS		= main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp \

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= violence

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -g

RM		= rm -rf

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all