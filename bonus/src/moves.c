/*
** moves.c for n4s in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May  4 13:24:36 2017 Léandre Blanchard
** Last update Thu May  4 19:50:05 2017 Léandre Blanchard
*/

#include "n4s.h"

static void		inertial(float *speed)
{
  if (KP(sfKeyUp) || KP(sfKeyZ))
    {
      if (*speed == 0)
	*speed = 0.15;
      if (*speed < MAX_SPEED)
	*speed *= ACCELERATION;
    }
  else if (KP(sfKeyDown) || KP(sfKeyS))
    {
      if (*speed >= 0)
	*speed -= 2;
      if (*speed <= 0 && *speed > -5)
	*speed -= 1 + (*speed * ACCELERATION);
    }
  else
    {
      if (*speed > 0)
	*speed /= 1.05;
      if (*speed < 0.05)
	*speed = 0;
    }
}

float			move_me(char **map, t_player *player)
{
  static float		speed;

  inertial(&speed);
  if (speed != 0)
    {
      if (KP(sfKeyLeft) || KP(sfKeyQ))
	player->info->dir -= ROLL;
      if (KP(sfKeyRight) || KP(sfKeyD))
	player->info->dir += ROLL;
    }
  if (mv_up(player->info, map, speed) == -1)
    speed = 0;
  return (speed);
}

static void		new_pos(t_info *info, float speed)
{
  if (speed > 0)
    {
      info->pos.x += WALLX;
      info->pos.y -= WALLY;
    }
  if (speed < 0)
    {
      speed *= -1;
      info->pos.x -= MOVEX;
      info->pos.y += MOVEY;
    }
}

static void		real_pos(sfVector2f prev, t_info *info, float speed)
{
  info->pos.x = prev.x + MOVEX;
  info->pos.y = prev.y - MOVEY;
}

int			mv_up(t_info *info, char **map, float speed)
{
  sfVector2f		prev;

  prev = info->pos;
  new_pos(info, speed);
  if (map[(int)info->pos.y][(int)info->pos.x] != '0')
    {
      if (map[(int)info->pos.y][(int)prev.x] == '0')
	{
	  info->pos = prev;
	  return (-1);
	}
      if (map[(int)prev.y][(int)info->pos.x] == '0')
	{
	  info->pos = prev;
	  return (-1);
	}
      info->pos = prev;
      return (-1);
    }
  if (speed > 0)
    real_pos(prev, info, speed);
  return (0);
}
