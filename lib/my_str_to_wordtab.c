/*
** my_str_to_wordtab.c for str_wordtab in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 26 19:18:18 2017 Léandre Blanchard
** Last update Sat Apr 29 20:47:18 2017 Léandre Blanchard
*/

#include "my.h"

typedef struct	s_vars
{
  int		i;
  int		j;
  int		k;
}		t_vars;

static void	init_vars(t_vars *v)
{
  v->i = 0;
  v->j = 0;
  v->k = 0;
}

static int	next_size(char *s, int no)
{
  int		i;

  i = 0;
  while (s[i] != no && s[i] != 0)
    i++;
  return (i);
}

static int     	find_words(char *s, int no)
{
  int		nb;
  int		i;

  nb = 0;
  i = 0;
  while (s[i] != 0)
    {
      if (s[i] == no)
	nb++;
      i++;
    }
  return (nb);
}

char		**my_str_to_wordtab(char *s, int no)
{
  char		**tab;
  t_vars	v;

  if (s == NULL)
    return (NULL);
  init_vars(&v);
  if ((tab = malloc(sizeof(char *) * find_words(s, no) + 8)) == NULL)
    return (NULL);
  while (s[v.i] != 0 && v.k != find_words(s, no) + 1)
    {
      v.j = 0;
      if ((tab[v.k] = my_calloc(next_size(s + v.i, no) + 1)) == NULL)
	return (NULL);
      while (s[v.i] != no && s[v.i] != 0)
	{
	  tab[v.k][v.j++] = s[v.i++];
	  tab[v.k][v.j] = 0;
	}
      v.k = v.k + 1;
      v.i = v.i + 1;
    }
  tab[v.k] = NULL;
  return (tab);
}
