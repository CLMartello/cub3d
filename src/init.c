
#include "../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->found = FALSE;
	map->height = 0;
	map->grid = NULL;
	map->player_orientation = -1;
	map->player_x = -1;
	map->player_y = -1;
}

void	init_img(t_img *img)
{
	int	i;

	i = 0;
	img->n_wall = NULL;
	img->s_wall = NULL;
	img->w_wall = NULL;
	img->e_wall = NULL;
	img->floor = malloc(sizeof(int) * 3);
	if (!img->floor)
		ft_error(img, ERR_MALLOC);
	img->ceiling = malloc(sizeof(int) * 3);
	if (!img->ceiling)
		ft_error(img, ERR_MALLOC);
	while (i < 3)
	{
		img->floor[i] = -1;
		img->ceiling[i] = -1;
		i++;
	}
}

t_img	*init_struct(void)
{
	t_img	*img;
	t_map	*map;

	img = malloc(sizeof(t_img));
	if (!img)
		ft_error(img, ERR_MALLOC);
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(img, ERR_MALLOC);
	img->map = map;
	init_img(img);
	init_map(img->map);
	return (img);
}
