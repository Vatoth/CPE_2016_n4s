##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Sun Jun  4 13:19:27 2017 
##

NAME	= ai

CC	= gcc

SRCS	= src/main.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -Werror -Wall -Wextra

CPPFLAGS += -I./include/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
	@       tput setaf 2; cat .tree; tput sgr0

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
