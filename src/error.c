
#include "../includes/cub3d.h"

void	free_db_str(char **db_str)
{
	int	i;

	i = 0;
	while (db_str[i])
	{
		free(db_str[i]);
		i++;
	}
	free(db_str);
}

void	free_map(t_map *map)
{
	if (map->grid)
		free_db_str(map->grid);
	free(map);
}

void	free_strs(t_img *img)
{
	if (img->line)
		free(img->line);
	if (img->n_wall)
		free(img->n_wall);
	if (img->s_wall)
		free(img->s_wall);
	if (img->w_wall)
		free(img->w_wall);
	if (img->e_wall)
		free(img->e_wall);
}

void	free_all(t_img	*img)
{
	if (img->map)
		free_map(img->map);
	if (img->fd != -1)
		close(img->fd);
	free_strs(img);
	if (img->floor)
		free(img->floor);
	if (img->ceiling)
		free(img->ceiling);
	if (img)
		free(img);
}

void	ft_error(t_img	*img, int type_error)
{
	printf("Error\n");
	if (type_error == ERR_ARGS)
		printf("Invalid argument\n");
	else if (type_error == ERR_MALLOC)
		printf("Error in malloc\n");
	else if (type_error == ERR_TEXT)
		printf("No access or missing texture\n");
	else if (type_error == ERR_RGB)
		printf("No RGB range or missing RGB\n");
	else if (type_error == ERR_MAP)
		printf("Invalid map or missing map\n");
	free_all(img);
	exit(1);
}
