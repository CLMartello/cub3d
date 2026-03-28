
#include "../includes/cub3d.h"

int ft_fill(char **map, int y, int x, int height)
{
    if (y < 0 || x < 0 || x >= (int)ft_strlen(map[y]) || y >= height || map[y][x] == ' ')
		return (0);
	else if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
    map[y][x] = 'F';
	if (!ft_fill(map, y + 1, x, height))
		return (0);
	if (!ft_fill(map, y, x + 1, height))
		return (0);
	if (!ft_fill(map, y - 1, x, height))
		return (0);
	if (!ft_fill(map, y, x - 1, height))
		return (0);
    return (1);
}

void	verify_map(t_img *img)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (img->map->height + 1));
	if (!map_copy)
		ft_error(img, ERR_MALLOC);
	while (img->map->grid[i])
	{
		map_copy[i] = get_line(img->map->grid[i]);
		i++;
	}
	map_copy[i] = NULL;
	if (ft_fill(map_copy, img->map->player_y, img->map->player_x, img->map->height) == 0)
	{
		free_db_str(map_copy);
		ft_error(img, ERR_MAP);
	}
	else
		free_db_str(map_copy);
}

int	is_map(t_img *img)
{
	int	i;

	i = 0;
	while (img->line[i] != '\0')
	{
		while (ft_isspace(img->line[i]) == 1)
			i++;
		if (ft_strchr("10", img->line[i]) == 1)
		{
			img->map->found = TRUE;
			return (1);
		}
		else
			break ;
	}
	return (0);
}

void	print_parse(t_img *img)
{
	int	i;

	i = 0;
	printf("Textures paths\nN: %s\nS: %s\nW: %s\nE: %s\n", img->n_wall, img->s_wall, img->w_wall, img->e_wall);
	printf("RGB of floor: %d, %d and %d \nRGB of ceiling: %d, %d and %d\n", img->floor[0], img->floor[1], img->floor[2], img->ceiling[0], img->ceiling[1], img->ceiling[2]);
	printf("Map:\n");
	while (img->map->grid[i])
	{
		printf("%s\n", img->map->grid[i]);
		i++;
	}
}
