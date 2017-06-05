/*
** time.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jun  5 15:53:21 2017 Léandre Blanchard
** Last update Mon Jun  5 15:53:44 2017 Léandre Blanchard
*/

#include "n4s.h"

void		init_time(t_time *timer)
{
  timer->start = clock();
}

void		update_time(t_time *timer)
{
  timer->end = clock();
  timer->time = ((double)(timer->end - timer->start)) / CLOCKS_PER_SEC * 1.1;
}
