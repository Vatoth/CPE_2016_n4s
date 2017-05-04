##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Thu May  4 20:41:51 2017 
##

NAME	= ai

CC	= gcc

LIB	= -L./lib -lmy -lm

SRCS	= src/main.c \
	  src/moves.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -Werror -g3 -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	##@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
