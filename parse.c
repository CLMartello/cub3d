
#include "../includes/cub3d.h"

void	start_map(char *line, t_img *img)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (img->map->height + 2));
	if (!new_map)
		ft_error(img, ERR_MALLOC);
	i = 0;
	if (img->map->grid)
	{
		while (img->map->grid[i])
		{
			new_map[i] = img->map->grid[i];
			i++;
		}
	}
	new_map[img->map->height] = get_line(line);
	new_map[img->map->height + 1] = NULL;
	if (img->map->grid)
		free(img->map->grid);
	img->map->grid = new_map;
	img->map->height++;
}

void	valid_map(char *line, t_img *img)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		while (ft_isspace(line[i]) == 1)
			i++;
		if (line[i] == '1' || line[i] == '0')
			i++;
		else if (line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'S' || line[i] == 'W')
		{
			verify_player(line[i], img);
			img->map->player_x = i;
			i++;
		}
		else if (line[i] == '\n')
			break ;
		else
		{
			free(line);
			ft_error(img, ERR_MAP);
		}
	}
	start_map(line, img);
}

int	parse_cub_file(char *file)
{
	int		fd;
	char	*line;
	t_img	*img;

	fd = -1;
	line = NULL;
	img = init_struct();
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(img, ERR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line) == 0)
			verify_conf(line, img);
		else if (is_map(line) == 1)
			valid_map(line, img);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	verify_map(img);
	//rendering(img);
	free_all(img);
	return (0);
}
