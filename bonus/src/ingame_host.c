/*
** in_game_host.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 12:29:27 2017 Léandre Blanchard
** Last update Thu May  4 19:35:01 2017 Léandre Blanchard
*/

#include "n4s.h"

static sfVector2f	player_start(char **map)
{
  int			i;
  int			j;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	{
	  if (map[i][j] == 'P')
	    {
	      map[i][j] = '0';
	      return (XY(j, i));
	    }
	  j++;
	}
      i++;
    }
  return (START);
}

char		**load_map(const char *pathname)
{
  char		*s;
  char		**map;
  int		fd;
  int		size;

  if ((fd = open(pathname, O_RDONLY)) < 0)
    return (NULL);
  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, 0);
  if ((s = my_calloc(size + 1)) == NULL)
    return (NULL);
  if ((read(fd, s, size)) < 0)
    return (NULL);
  if (s[my_strlen(s) - 1] == '\n')
    s[my_strlen(s) - 1] = 0;
  if ((map = my_str_to_wordtab(s, '\n')) == NULL)
    return (NULL);
  free(s);
  if (my_tablen(map) < 4 || my_strlen(map[0]) < 4)
    {
      free_tab(map);
      return (NULL);
    }
  size = 0;
  while (map[size] != NULL)
    my_revstr(map[size++]);
  close(fd);
  return (map);
}

static void	display_background(t_window *window, t_texture *textures)
{
  static int	a;

  put_sprite(window, SPRITE(ROAD), XY(0, H_2));
  put_sprite(window, SPRITE(CLOUDS), XY((-a) / 10, 0));
  put_sprite(window, SPRITE(CLOUDS), XY((1280 - a) / 10, 0));
  a = (a + 1) % (1280 / 10);
}

void		display_me(t_window *window, t_texture *textures, t_player *players)
{
  static float		a = 5;

  if (KP(sfKeyLeft) || KP(sfKeyQ))
    {
      if (a > 1)
	a -= 0.5;
    }
  else if (KP(sfKeyRight) || KP(sfKeyD))
    {
      if (a < 9)
	a += 0.5;
    }
  else
    a = 5;
  put_sprite_resize(window, textures->karts[players[0].info->skin][(int)a],
		    XY(W_2 - 90, H_ - 192), XY(6, 6));
}

void		special_refresh(t_window *window)
{
  sfTexture_updateFromPixels(window->texture, window->pixels,
			     window->width, window->height, 0, 0);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
}

int		ingame_host(t_window *window, t_texture *textures,
			    t_player *players)
{
  char		**map;

  if ((map = load_map(MAP_PATH)) == NULL)
    return (-1);
  players[0].info->pos = player_start(map);
  players[0].info->dir = 90;
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      close_win(window);
      move_me(map, &players[0]);
      display_background(window, textures);
      walls(window, map, textures, &players[0]);
      special_refresh(window);
      display_me(window, textures, players);
      sfRenderWindow_display(window->window);
    }
  free_tab(map);
  return (0);
}
