/*
** main.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 12:10:35 2017 Léandre Blanchard
** Last update Tue May  2 17:18:44 2017 Léandre Blanchard
*/

#include "n4s.h"

#include <fcntl.h>

int			call_info(void)
{
  my_printf("GET_INFO_LIDAR\n");
  return (0);
}

int			main(void)
{
  my_printf("%s\n", START_SIM);
  call_info();
  my_printf("%s\n", STOP_SIM);
  return (0);
}
