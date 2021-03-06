/*
** my_alloc_tab.c for alloc_tab in /home/leandre/Games/Tetris
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 17 18:13:15 2017 Léandre Blanchard
** Last update Tue May  9 16:41:14 2017 Léandre Blanchard
*/

#include "my.h"

char		**my_alloc_tab(int height, int width)
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * height + 8)) == NULL)
    return (NULL);
  while (i != height)
    {
      if ((tab[i] = malloc(sizeof(char) * width + 1)) == NULL)
	return (NULL);
      zeros(tab[i], width + 1);
      i++;
    }
  tab[height] = NULL;
  return (tab);
}
