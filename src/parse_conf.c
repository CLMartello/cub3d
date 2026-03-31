/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:42:20 by clumertz          #+#    #+#             */
/*   Updated: 2026/03/31 19:42:39 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	parse_rgb(t_img *img, int *rgb, int pos)
{
	int	i;

	i = 0;
	verify_text(img);
	while (img->line[pos] != '\0' && i < 3)
	{
		while (img->line[pos] == ' ' || img->line[pos] == ',')
			pos++;
		if (img->line[pos] >= '0' && img->line[pos] <= '9')
		{
			rgb[i] = ft_atoi(img->line + pos);
			i++;
			while (img->line[pos] >= '0' && img->line[pos] <= '9')
				pos++;
		}
		else
			break ;
	}
	i = 0;
	while (i < 3)
	{
		if (rgb[i] == -1 || rgb[i] > 255)
			ft_error(img, ERR_RGB);
		i++;
	}
}

void	parse_texture(t_img *img, int pos)
{
	int		i;
	char	*path;

	i = pos + 2;
	path = NULL;
	while (ft_isspace(img->line[i]) == 1)
		i++;
	path = get_line(img->line + i);
	if (access(path, F_OK | R_OK) == -1)
	{
		free(path);
		ft_error(img, ERR_TEXT);
	}
	else if (ft_strncmp(img->line + pos, "NO", 2) && !img->n_wall)
		img->n_wall = path;
	else if (ft_strncmp(img->line + pos, "SO", 2) && !img->s_wall)
		img->s_wall = path;
	else if (ft_strncmp(img->line + pos, "WE", 2) && !img->w_wall)
		img->w_wall = path;
	else if (ft_strncmp(img->line + pos, "EA", 2) && !img->e_wall)
		img->e_wall = path;
}

void	verify_conf(t_img *img)
{
	int	i;

	i = 0;
	while (ft_isspace(img->line[i]) == 1)
		i++;
	if (ft_strchr("NSWE", img->line[i]))
		parse_texture(img, i);
	else if (img->line[i] == 'F')
		parse_rgb(img, img->floor, i + 1);
	else if (img->line[i] == 'C')
		parse_rgb(img, img->ceiling, i + 1);
}
