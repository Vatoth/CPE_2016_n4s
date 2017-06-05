/*
** main.c for  in /home/vatoth/Epitech/CPE_2016_n4s/src
** 
** Made by 
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon May 22 17:52:06 2017 
** Last update Mon Jun  5 14:55:28 2017 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "n4s.h"

static void	get_info(t_info *info, char *line)
{
  char		*pointer;
  char		*tmp;
  int		i;

  i = 0;
  if ((tmp = calloc(strlen(line) + 1, sizeof(char))) == NULL)
    exit (84);
  strcpy(tmp, line);
  strtok(tmp, ":");
  info->middle = -1;
  info->left = -1;
  info->right = -1;
  while ((pointer = strtok(NULL, ":")) != NULL)
    {
      if (i == 17)
	info->middle = atof(pointer);
      if (i < 17)
	info->left = info->left + atof(pointer);
      if (i > 17)
	info->right = info->right + atof(pointer);
      i += 1;
    }
  info->right = info->right / 15;
  info->left = info->left / 15;
  free(tmp);
}

static void		move_forward(char *line)
{
  t_info		lidar;
  float			move;

  get_info(&lidar, line);
  move = 0;
  if (lidar.middle >= 2000)
    move = 1.0;
  else if (lidar.middle >= 1500)
    move = 0.7;
  else if (lidar.middle >= 1250)
    move = 0.65;
  else if (lidar.middle >= 1000)
    move = 0.40;
  else if (lidar.middle >= 600)
    move = 0.35;
  else if (lidar.middle >= 400)
    move = 0.15;
  else if (lidar.middle >= 200)
    move = 0.1;
  else
    move = 0.05;
  dprintf(1, "CAR_FORWARD:%.3f\n", move);
}

static void		turn(char *line)
{
  t_info		lidar;
  float			my_turn;

  get_info(&lidar, line);
  my_turn = 0;
  if (lidar.middle >= 1500)
    my_turn = 0.005;
  else if (lidar.middle >= 1000)
    my_turn = 0.05;
  else if (lidar.middle >= 600)
    my_turn = 0.1;
  else if (lidar.middle >= 400)
    my_turn = 0.275;
  else if (lidar.middle >= 200)
    my_turn = 0.345;
  else
    my_turn = 0.95;
  if ((lidar.left - lidar.right ) < 0)
    dprintf(1, "WHEELS_DIR:-%f\n", my_turn);
  else
    dprintf(1, "WHEELS_DIR:%f\n", my_turn);
}

static int	track_clear(char *line)
{
  char		*pointer;
  char		*tmp;

  if ((tmp = calloc(strlen(line) + 1, sizeof(char))) == NULL)
    exit (0);
  strcpy(tmp, line);
  strtok(tmp, ":");
  while ((pointer = (strtok(NULL, ":"))) != NULL)
    {
      if (strcmp(pointer, "Track Cleared") == 0)
	{
	  dprintf(1, "STOP_SIMULATION\n");
	  {
	    free(tmp);
	    return (1);
	  }
	}
    }
  free(tmp);
  return (0);
}

int		main(void)
{
  size_t	n;
  char		*line;

  n = 0;
  line = NULL;
  dprintf(1, "START_SIMULATION\n");
  if (getline(&line, &n, stdin) == -1 || track_clear(line) == 1)
    return (EXIT_SUCCESS);
  dprintf(1, "GET_INFO_LIDAR\n");
  while (getline(&line, &n, stdin) != -1)
    {
      if ((track_clear(line)) == 1)
	return (EXIT_SUCCESS);
      move_forward(line);
      if (getline(&line, &n, stdin) == -1 || track_clear(line) == 1)
	return (EXIT_SUCCESS);
      dprintf(1, "GET_INFO_LIDAR\n");
      if (getline(&line, &n, stdin) == -1 || track_clear(line) == 1)
	return (EXIT_SUCCESS);
      turn(line);
      if (getline(&line, &n, stdin) == -1 || track_clear(line) == 1)
	return (EXIT_SUCCESS);
      dprintf(1, "GET_INFO_LIDAR\n");
    }
  return (EXIT_SUCCESS);
}
