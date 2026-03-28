
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

void	parse_rgb(char *line, int *rgb, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && j < 3)
	{
		while (line[i] == ' ' || line[i] == ',')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			rgb[j] = ft_atoi(line + i);
			if (rgb[j] > 255)
				ft_error(img, ERR_RGB);
			j++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		else
			return ;
	}
}

void	parse_texture(char *line, int pos, t_img *img)
{
	int		i;
	char	*path;

	i = pos + 2;
	path = NULL;
	while (ft_isspace(line[i]) == 1)
		i++;
	path = get_line(line + i);
	if (access(path, F_OK | R_OK) == -1)
	{
		free(path);
		ft_error(img, ERR_TEXT);
	}
	else if (line[pos] == 'N' && !img->n_wall)
		img->n_wall = path;
	else if (line[pos] == 'S' && !img->s_wall)
		img->s_wall = path;
	else if (line[pos] == 'W' && !img->w_wall)
		img->w_wall = path;
	else if (line[pos] == 'E' && !img->e_wall)
		img->e_wall = path;
}

void	verify_conf(char *line, t_img *img)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		parse_texture(line, i, img);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		parse_texture(line, i, img);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		parse_texture(line, i, img);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		parse_texture(line, i, img);
	else if (line[i] == 'F')
		parse_rgb(line + 1, img->floor, img);
	else if (line[i] == 'C')
		parse_rgb(line + 1, img->ceiling, img);
}
