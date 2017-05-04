/*
** init_textures.c for tek_kart in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue May  2 18:39:04 2017 Léandre Blanchard
** Last update Thu May  4 15:20:50 2017 Léandre Blanchard
*/

#include "n4s.h"

static int		fill_karts(t_sprite **sprites, const char *pathname)
{
  sfTexture		*texture;
  int			x;

  x = 0;
  if ((texture = sfTexture_createFromFile(pathname, NULL)) == NULL)
    return (-1);
  while (sprites[x] != NULL)
    {
      sprites[x]->texture = texture;
      sprites[x]->sprite = sfSprite_create();
      sfSprite_setTexture(sprites[x]->sprite, texture, sfTrue);
      sfSprite_setTextureRect(sprites[x]->sprite,
			      (sfIntRect){x * 30, 0, 30, 32});
      x++;
    }
  return (0);
}

static sfImage		**init_images(void)
{
  int			i;
  sfImage		**images;
  char			*s;
  char			*nb;

  i = 0;
  if ((images = malloc(sizeof(sfImage *) * NB_IMAGES + 8)) == NULL)
    return (NULL);
  while (i != NB_IMAGES)
    {
      if ((nb = int_char(i)) == NULL)
	return (NULL);
      if ((s = my_catalloc(PATH_IMAGES, nb, ".png")) == NULL)
	return (NULL);
      if ((images[i] = sfImage_createFromFile(s)) == NULL)
	return (NULL);
      free(s);
      free(nb);
      i++;
    }
  images[i] = NULL;
  return (images);
}

static int		all_karts(t_sprite ***sprites)
{
  struct dirent		*folder;
  DIR			*dir;
  char			*s;
  int			i;

  i = 0;
  my_printf(BOX_, BOLDWHITE, RESET);
  if ((dir = opendir(KART_FOLDER)) == NULL)
    return (-1);
  while ((folder = readdir(dir)) != NULL && i != NB_KARTS)
    if (end_with(folder->d_name, ".png") == 0)
      {
	if ((s = my_catalloc(KART_FOLDER, folder->d_name, NULL)) == NULL)
	  return (-1);
	my_printf(BOLDRED);
	if ((fill_karts(sprites[i], s)) == -1)
	  return (-1);
	my_printf(KART_FOUND, BOLDGREEN, BOLDCYAN, s, BOLDGREEN, RESET);
	free(s);
	i++;
      }
  closedir(dir);
  my_printf(BOX_, BOLDWHITE, RESET);
  return (0);
}

static t_sprite		*load_one(const char *pathname, const char *name)
{
  t_sprite		*sprite;

  if ((sprite = create_sprite(pathname)) == NULL)
    return (NULL);
  my_printf(SPRITE_FOUND, BOLDGREEN, BOLDYELLOW, name,
	    BOLDGREEN, RESET);
  return (sprite);
}

static int		all_sprites(t_sprite **sprites)
{
  int			i;

  sprites[0] = load_one("sprites/lobby.png", "lobby.png");
  sprites[1] = load_one("sprites/button.png", "button.png");
  sprites[2] = load_one("sprites/button_pressed.png", "button_pressed.png");
  sprites[3] = load_one("sprites/clouds.png", "clouds.png");
  sprites[4] = load_one("sprites/road.png", "road.png");
  i = 0;
  while (i != NB_SPRITES)
    if (sprites[i++] == NULL)
      return (-1);
  sprites[NB_SPRITES] = NULL;
  my_printf(BOX_, BOLDWHITE, RESET);
  return (0);
}

t_texture		*init_textures(void)
{
  t_texture		*textures;
  int			i;

  i = 0;
  if ((textures = malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  if ((textures->images = init_images()) == NULL)
    return (NULL);
  if ((textures->karts = malloc(8 * NB_KARTS + 8)) == NULL)
    return (NULL);
  textures->karts[NB_KARTS] = NULL;
  if ((textures->sprites = malloc(16 * NB_SPRITES + 8)) == NULL)
    return (NULL);
  textures->karts[NB_SPRITES] = NULL;
  while (i != NB_KARTS)
    if ((textures->karts[i++] = create_sprites(11)) == NULL)
      return (NULL);
  if (all_karts(textures->karts) == -1 ||
      all_sprites(textures->sprites) == -1)
    return (NULL);
  if ((textures->lakitu = lakitu()) == NULL)
    return (NULL);
  return (textures);
}
