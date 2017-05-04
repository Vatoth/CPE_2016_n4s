/*
** n4s.h for n4s in /home/leandre/Prog_elem/CPE_2016_n4s
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 12:11:32 2017 Léandre Blanchard
** Last update Tue May  2 16:43:17 2017 Léandre Blanchard
*/

#ifndef N4S_H_
# define N4S_H_

# include <stdio.h>

# include "my.h"
# include "colors.h"
# include "defines.h"

int		move(float speed);

int		wait_cycle(int nb);

int		backward(float speed);

int		turn(float axis);

#endif /* !N4S_H_ */
