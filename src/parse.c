/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:37:29 by clumertz          #+#    #+#             */
/*   Updated: 2026/03/31 19:38:01 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	verify_arg(char *line)
{
	int	i;

	i = ft_strlen(line);
	if ((ft_strncmp(line + (i - 4), ".cub", 4)) != 0)
		ft_error(NULL, ERR_ARGS);
}

void	verify_text(t_img *img)
{
	if (!img->n_wall || !img->s_wall || !img->w_wall || !img->e_wall)
		ft_error(img, ERR_TEXT);
}

void	start_map(t_img *img)
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
	new_map[img->map->height] = get_line(img->line);
	new_map[img->map->height + 1] = NULL;
	if (img->map->grid)
		free(img->map->grid);
	img->map->grid = new_map;
	img->map->height++;
}

void	valid_map(t_img *img)
{
	int	i;

	i = 0;
	while (img->line[i] != '\0')
	{
		while (ft_isspace(img->line[i]) == 1)
			i++;
		if (img->line[i] == '1' || img->line[i] == '0')
			i++;
		else if (img->line[i] == 'N' || img->line[i] == 'E'
			|| img->line[i] == 'S' || img->line[i] == 'W')
		{
			if (img->map->player_orientation != -1)
				ft_error(img, ERR_MAP);
			img->map->player_orientation = img->line[i];
			img->map->player_y = img->map->height;
			img->map->player_x = i;
			i++;
		}
		else if (img->line[i] == '\n')
			break ;
		else
			ft_error(img, ERR_MAP);
	}
	start_map(img);
}

void	parse_cub_file(char *file, t_img *img)
{
	img->fd = open(file, O_RDONLY);
	if (img->fd == -1)
		ft_error(img, ERR_ARGS);
	img->line = get_next_line(img->fd);
	while (img->line)
	{
		is_map(img);
		if (img->map->found == FALSE)
			verify_conf(img);
		else
			valid_map(img);
		free(img->line);
		img->line = NULL;
		img->line = get_next_line(img->fd);
	}
	verify_map(img);
}
