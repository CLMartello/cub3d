
#include "../includes/cub3d.h"

void	verify_arg(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if ((ft_strncmp(line + (i - 4), ".cub", 4)) != 0)
		ft_error(NULL, ERR_ARGS);
}

void	verify_all(t_img *img)
{
	if (!img->n_wall || !img->s_wall || !img->w_wall || !img->e_wall)
		ft_error(img, ERR_TEXT);
	if (img->floor[0] == -1 || img->floor[1] == -1 || img->floor[2] == -1)
		ft_error(img, ERR_RGB);
	if (img->ceiling[0] == -1 || img->ceiling[1] == -1 || img->ceiling[2] == -1)
		ft_error(img, ERR_RGB);
	verify_map(img);
}

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

void	parse_cub_file(char *file, t_img *img)
{
	int		fd;
	char	*line;

	
	fd = -1;
	line = NULL;
	verify_arg(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(img, ERR_OPEN);
	line = get_next_line(fd);
	while (line)
	{
		is_map(line, img);
		if (img->map->found == FALSE)
			verify_conf(line, img);
		else
			valid_map(line, img);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	verify_all(img);
}
