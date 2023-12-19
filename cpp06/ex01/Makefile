SRCS		= main.cpp \
				Serializer.cpp \

OBJS		= $(SRCS:.cpp=.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= Serializer

all: $(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -g

RM		= rm -rf

t: re
	clear
	./Serializer

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all