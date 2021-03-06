/*
** clear_win.c for clear_win in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:04:57 2017 Léandre Blanchard
** Last update Thu May  4 14:34:24 2017 Léandre Blanchard
*/

#include "csfml.h"

void            window_clear(t_window *window)
{
  sfRenderWindow_clear(window->window, sfWhite);
}

void            window_refresh(t_window *window)
{
  sfTexture_updateFromPixels(window->texture, window->pixels,
			     window->width, window->height, 0, 0);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  sfRenderWindow_display(window->window);
}

void		clear_white(t_window *window)
{
  int		i;

  i = 0;
  while (i != window->height * 4 * window->width)
    window->pixels[i++] = 255;
}
