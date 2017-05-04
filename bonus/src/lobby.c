/*
** lobby.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 13:47:25 2017 Léandre Blanchard
** Last update Thu May  4 12:44:57 2017 Léandre Blanchard
*/

#include "n4s.h"

static int	your_ip()
{
  my_printf(Y_IP, BOLDWHITE, BOLDYELLOW,
	    sfIpAddress_getLocalAddress().address,
	    BOLDCYAN, BOLDYELLOW,
	    sfIpAddress_getPublicAddress(sfSeconds(4)).address,
	    RESET);
  return (0);
}

static int	button(t_window *window, t_texture *textures, t_player *players)
{
  put_sprite(window, SPRITE(BUTTON), XY(W_ - 200, H_ - 100));
  pos_mouse(window);
  if (window->mouse.x > W_ - 200 && window->mouse.x < W_ - 100
      && window->mouse.y > H_ - 100  && window->mouse.y < H_ - 70)
    {
      put_sprite(window, SPRITE(BUTTON_PRESSED), XY(W_ - 200, H_ - 100));
      if (MP)
	players[0].info->dir = 0;
    }
  return (0);
}

static int	display(t_window *window, t_texture *textures, t_player *players)
{
  static int	a;
  int		i;
  int		kart;

  i = 0;
  put_sprite(window, SPRITE(LOBBY), ORIGIN);
  put_sprite(window, textures->lakitu[a / 35  % 8],
	     XY(W_2 + 10 * cos((float)a / 20), 50 + 10 * sin((float)a / 20)));
  button(window, textures, players);
  while (i < MAX_PLAYERS)
    {
      if ((kart = players[i].info->skin) > -1)
	{
	  put_sprite_resize(window, textures->karts[kart][5],
			    XY(100 + i * 150, H_2 + 200), XY(3, 3));
	  put_word(players[i].info->name,
		   XY(100 + i * 150, H_2 + 100), window, sfBlack);
	}
      i++;
    }
  a = (a + 1) % 1600;
  return (0);
}

int		lobby(t_window *window, t_texture *textures, t_player *players)
{
  sfThread	*listen;
  sfThread	*sockets;

  your_ip();
  listen = sfThread_create((void *)listener, (void *)players);
  sockets = sfThread_create((void *)sockets_manager_host, (void *)players);
  sfThread_launch(listen);
  sfThread_launch(sockets);
  while (sfRenderWindow_isOpen(window->window) && players[0].info->dir != 0)
    {
      if (players[0].info->skin == -2)
	sfRenderWindow_close(window->window);
      window_clear(window);
      display(window, textures, players);
      close_win(window);
      window_refresh(window);
    }
  free_thread(listen);
  if (players[0].info->dir == 0)
    ingame_host(window, textures, players);
  players[0].info->skin = -1;
  usleep(2000);
  free_thread(sockets);
  return (0);
}
