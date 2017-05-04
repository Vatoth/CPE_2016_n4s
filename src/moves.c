/*
** moves.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 12:13:49 2017 Léandre Blanchard
** Last update Tue May  2 17:13:03 2017 Léandre Blanchard
*/

#include "n4s.h"

int		turn(float axis)
{
  printf("%s%f\n", DIRECTION, axis);
  return (0);
}

int		wait_cycle(int nb)
{
  printf("%s%d\n", WAIT_CYCLE, nb);
  return (0);
}

int		move(float speed)
{
  if (speed > 0)
    printf("%s%f\n", FORWARD, speed);
  if (speed < 0)
    printf("%s%f\n", BACKWARD, -speed);
  return (0);
}
