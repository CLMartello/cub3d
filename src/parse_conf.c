
#include "../includes/cub3d.h"

int	ft_atoi(char *nbr)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		value = value * 10 + (nbr[i] - '0');
		i++;
	}
	return (value);
}

void	parse_rgb(char *line, int *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 3)
	{
		if (line[i] == ' ' || line[i] == ',')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			rgb[j] = ft_atoi(line + i);
			if (rgb[j] > 255)
				ft_error(NULL, ERR_RGB);
			j++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else
			return ;
	}
}

void	parse_texture(char *line, t_img *img)
{
	int		i;
	char	*path;

	i = 2;
	path = NULL;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
		path = get_line(line + i);
	if (access(path, F_OK | R_OK) == -1)
		ft_error(img, ERR_ARGS);
	if (line[0] == 'N')
		img->n_wall = path;
	else if (line[0] == 'S')
		img->s_wall = path;
	else if (line[0] == 'W')
		img->w_wall = path;
	else if (line[0] == 'E')
		img->e_wall = path;
}

void	verify_conf(char *line, t_img *img)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		parse_texture(line, img);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		parse_texture(line, img);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		parse_texture(line, img);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		parse_texture(line, img);
	else if (line[i] == 'F')
		parse_rgb(line + 1, img->floor);
	else if (line[i] == 'C')
		parse_rgb(line + 1, img->ceiling);
}
