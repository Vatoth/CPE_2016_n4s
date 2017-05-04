/*
** send.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:18:05 2017 Léandre Blanchard
** Last update Thu May  4 11:29:29 2017 Léandre Blanchard
*/

#include "n4s.h"

void		host_send(t_player *players)
{
  int		i;
  int		j;
  size_t	size;

  i = 0;
  while (i < MAX_PLAYERS)
    {
      j = 0;
      while (j < MAX_PLAYERS && players[i].info->skin != -1)
	{
	  if (i != j && my_strlen(players[j].info->name) != 0)
	    {
	      sfTcpSocket_sendPartial(players[i].socket,
				      players[j].info, sizeof(t_info), &size);
	    }
	  j++;
	}
      i++;
    }
}

void		client_send(t_player *player)
{
  size_t	size;

  if (player[0].info->skin != -2)
    if ((sfTcpSocket_sendPartial(player->socket, player->info,
				 sizeof(t_info), &size))
	== sfSocketDisconnected)
      {
	player[0].info->skin = -2;
	my_printf("%sHost Disconnected\n%s", BOLDRED, RESET);
      }
  if (size != sizeof(t_info))
    my_printf(SEND_ERR, BOLDWHITE, BOLDCYAN, sizeof(t_info) - size,
	      BOLDWHITE, RESET);
}
