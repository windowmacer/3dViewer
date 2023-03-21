NAME		:= 3DViewer

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -std=c11 #-fsanitize=address
RM			= rm -f

INCS_DIR	= ./Users/kirill/Desktop/parser/


INCS		=	-I include
SRCS		=	fillingNode.c get_next_line.c parserOBJ.c utilsNode.c main.c
OBJS		=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re

