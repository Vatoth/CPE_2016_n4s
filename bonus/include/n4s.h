/*
** n4s.h for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 18:25:26 2017 Léandre Blanchard
** Last update Thu May  4 19:51:57 2017 Léandre Blanchard
*/

#ifndef N4S_H_
# define N4S_H_

# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# include "my.h"
# include "colors.h"
# include "my_csfml.h"

# define DIST_ 0.01
# define NAME_SIZE 20
# define FOV 90
# define ROLL 3 + speed / 40
# define ACCELERATION 1.1
# define MAX_SPEED 20
# define MOVEX speed / 100 * cos(M_PI / 180.0 * info->dir)
# define MOVEY speed / 100 * sin(M_PI / 180.0 * info->dir)
# define WALLX 0.7 * cos(M_PI / 180.0 * info->dir)
# define WALLY 0.7 * sin(M_PI / 180.0 * info->dir)
# define PROJ window->width / 2 * tan(30 * M_PI / (180 - FOV * 2 / 3))
# define TEXTURE_SIZE 64
# define USAGE1 "%s./tek_kart --join [ip_address] [nickname]%s%s\n"
# define USAGE2 "\n./tek_kart --server [nickname]"
# define SEND_ERR "%sPacket missed %s%d%s bytes in send :/%s\n"
# define PATH_IMAGES "images/wall"
# define NB_IMAGES 3
# define NB_KARTS 6
# define NB_SPRITES 5
# define KART_FOUND "%sSprites of kart in %s%s%s loaded\n%s"
# define PLAYER_DC "%sPlayer n°%d left the game\n%s"
# define KART_FOLDER "karts/"
# define SPRITES_FOLDER "sprites/"
# define SPRITE_FOUND "%sSprite ingame : %s%s%s loaded\n%s"
# define MAX_PLAYERS 4
# define MISSING_SPRITES "%sMissing sprites in ./sprites or ./karts :( %s\n"
# define BOX_ "%so----------------------------------------------------o%s\n"
# define XY(x, y) xy_vectorf(x, y)
# define XYI(x, y) xy_vectori(x, y)
# define ORIGIN xy_vectorf(0, 0)
# define H_ window->height
# define W_ window->width
# define H_2 window->height / 2
# define W_2 window->width / 2
# define Y_IP "\n%sYour Local ip is : %s%s%s\nYour Public ip is : %s%s%s\n"
# define PORT 4687
# define LOBBY 0
# define BUTTON 1
# define BUTTON_PRESSED 2
# define CLOUDS 3
# define ROAD 4
# define START xy_vectorf(4, 4)
# define SPRITE(x) textures->sprites[x]
# define MAP_PATH "maps/basic.n4s"

typedef struct	s_rot
{
  sfVector2i	pos;
  float		angle;
}		t_rot;

typedef struct	s_cast
{
  float		dist;
  int		texture;
  float		wall_h;
  int		change;
  float		x;
}		t_cast;

typedef struct	s_texture
{
  sfImage	**images;
  t_sprite	***karts;
  t_sprite	**sprites;
  t_sprite	**lakitu;
}		t_texture;

typedef struct	s_info
{
  char		name[NAME_SIZE];
  sfVector2f	pos;
  int		skin;
  float		dir;
}		t_info;

typedef struct	s_player
{
  t_info	*info;
  sfTcpSocket	*socket;
}		t_player;

float		move_me(char **map, t_player *player);

int		mv_up(t_info *info, char **map, float speed);

int             ingame_host(t_window *window, t_texture *textures,
			    t_player *players);

char            **load_map(const char *pathname);

t_texture	*init_textures(void);

void            free_textures(t_texture *textures);

void		free_players(t_player *players);

int             client(t_window *window, t_texture *textures,
		       t_player *players, sfIpAddress addr);

void		special_clear(t_window *window);

int		lobby(t_window *window, t_texture *textures, t_player *players);

t_player	*init_players(int nb);

t_sprite	**lakitu(void);

int		listener(t_player *players);

void		host_send(t_player *players);

void		client_send(t_player *player);

void		walls(t_window *window, char **map, t_texture *textures,
		      t_player *player);

void		host_receive(t_player *players);

int		client_receive(t_player *players);

void		sockets_manager_host(t_player *players);

void		sockets_manager_client(t_player *players);

int		first_inactive_player(t_player *players);

#endif /* !N4S_H_ */
