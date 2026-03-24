
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

void	free_all(t_img	*img)
{
	if (img->map)
		free_map(img->map);
	if (img->n_wall)
		free(img->n_wall);
	if (img->s_wall)
		free(img->s_wall);
	if (img->w_wall)
		free(img->w_wall);
	if (img->e_wall)
		free(img->e_wall);
	if (img->floor)
		free(img->floor);
	if (img->ceiling)
		free(img->ceiling);
	free(img);
}

void	ft_error(t_img	*img, int type_error)
{
	if (type_error == ERR_OPEN)
		printf("Unable to read .cub file.\n");
	else if (type_error == ERR_MALLOC)
		printf("Error in malloc.\n");
	else if (type_error == ERR_ACCESS)
		printf("No access to read texture.\n");
	else if (type_error == ERR_RGB)
		printf("RGB must be between 0 and 255.\n");
	else if (type_error == ERR_MAP)
		printf("Invalid map.\n");
	if (img)
		free_all(img);
	exit(1);
}
