/*
** client.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:40:29 2017 Léandre Blanchard
** Last update Wed May 31 21:31:06 2017 Léandre Blanchard
*/

#include "n4s.h"

static int	connect_socket(sfTcpSocket *socket, sfIpAddress *addr)
{
  int		a;

  a = 0;
  if (my_strcmp(addr->address, "0.0.0.0") == 0)
    return (-1);
  while ((sfTcpSocket_connect(socket, *addr, PORT, sfSeconds(10)))
	 != sfSocketDone && a < 10000)
    a++;
  if (a >= 10000)
    {
      my_printf("%sCan't connect to %s%s%s <Timedout>\n%s",
		BOLDRED, BOLDCYAN, addr->address, BOLDRED, RESET);
      return (-1);
    }
  sfTcpSocket_setBlocking(socket, sfFalse);
  return (0);
}

static int	display(t_window *window, t_texture *textures,
			t_player *players)
{
  static int    a;
  int           i;
  int           kart;

  i = 0;
  put_sprite(window, textures->sprites[0], ORIGIN);
  put_sprite(window, textures->lakitu[a / 35  % 8],
	     XY(W_2 + 10 * cos((float)a / 20), 50 + 10 * sin((float)a / 20)));
  if (key_released(sfKeySpace))
    players[0].info->skin = (players[0].info->skin + 1) % NB_KARTS;
  while (i < MAX_PLAYERS)
    {
      if ((kart = players[i].info->skin) > -1
	  && players[i].info->status > -1)
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

int		client(t_window *window, t_texture *textures,
		       t_player *players, sfIpAddress addr)
{
  sfThread	*thread;

  if ((connect_socket(players[0].socket, &addr)) != 0)
    return (-1);
  thread = sfThread_create((void *)sockets_manager_client, (void *)players);
  sfThread_launch(thread);
  while (sfRenderWindow_isOpen(window->window)
	 && players[1].info->status != 1)
    {
      window_clear(window);
      display(window, textures, players);
      close_win(window);
      window_refresh(window);
    }
  if (players[1].info->status == 1)
    ingame_client(window, textures, players);
  players[0].info->status = -1;
  usleep(2000);
  free_thread(thread);
  return (0);
}
