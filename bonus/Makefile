##
## Makefile for *** in /home/leandre/***
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Thu May  4 20:42:08 2017 
##

NAME	= tek_kart

CC	= gcc

LIB	= -L./lib -lmy -lc_graph_prog_full -L./lib/CSFML -l_my_csfml -lm

SRCS	= src/main.c \
	  src/init_textures.c \
	  src/init_players.c \
	  src/free.c \
	  src/lobby.c \
	  src/gogoby.c \
	  src/listener.c \
	  src/send.c \
	  src/receive.c \
	  src/thread.c \
	  src/client.c \
	  src/ingame_host.c \
	  src/raycast.c \
	  src/moves.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -g3 -Wall -Wextra -I ./include -O2

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
