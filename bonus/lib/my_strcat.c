/*
** my_strcat.c for my_strcat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 09:27:45 2016 Leandre Blanchard
** Last update Tue Jun 13 17:54:29 2017 
*/

#include "my.h"

int	my_strcat(char *dest, const char *src)
{
  char	*ret;

  if (dest == NULL || src == NULL)
    return (-1);
  ret = dest;
  while (*dest)
    dest++;
  while ((*dest++ = *src++));
  return (0);
}
