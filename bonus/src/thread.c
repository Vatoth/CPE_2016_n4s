/*
** thread.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 17:29:23 2017 Léandre Blanchard
** Last update Thu May  4 17:24:32 2017 Léandre Blanchard
*/

#include "n4s.h"

void		sockets_manager_host(t_player *players)
{
  while (players[0].info->skin > 0)
    {
      host_receive(players);
      usleep(1000);
      host_send(players);
      usleep(1000);
    }
}

void		sockets_manager_client(t_player *players)
{
  while (players[0].info->skin > 0)
    {
      client_receive(players);
      usleep(1000);
      client_send(&players[0]);
      usleep(1000);
    }
}
