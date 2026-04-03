/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:20:41 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 17:01:41 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	put_pixel(t_game *game, int x, int y, int *color)
{
	int	index;

	if (!game || x >= WIDTH || x < 0 || y >= HEIGHT || y < 0 || !color)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color[2];
	game->data[index + 1] = color[1];
	game->data[index + 2] = color[0];
}
void	draw_pov(t_game *game, float dist, int side, float ray_dir_x, float ray_dir_y, int i)
{
	t_tex			*tex;
	float			wall_x;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	float			step;
	float			tex_pos;
	int				y;
	unsigned int	color;

	if (dist < 0.0001f)
		dist = 0.0001f;

	if (side == 0)
		tex = (ray_dir_x > 0) ? game->e_wall : game->w_wall;
	else
		tex = (ray_dir_y > 0) ? game->s_wall : game->n_wall;

	/* hit point on the wall in map-cell units */
	if (side == 0)
		wall_x = (game->player.y / (float)BLOCK) + dist * ray_dir_y;
	else
		wall_x = (game->player.x / (float)BLOCK) + dist * ray_dir_x;
	wall_x -= floorf(wall_x);

	line_h = (int)(HEIGHT / dist);
	if (line_h < 1)
		line_h = 1;

	draw_start = -line_h / 2 + HEIGHT / 2;
	draw_end = line_h / 2 + HEIGHT / 2;

	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;

	tex_x = (int)(wall_x * (float)tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;

	/* Flip texture horizontally so wall sides face correctly */
	if ((side == 0 && ray_dir_x < 0) || (side == 1 && ray_dir_y > 0))
    	tex_x = tex->width - tex_x - 1;

	step = (float)tex->height / (float)line_h;
	tex_pos = (draw_start - HEIGHT / 2.0f + line_h / 2.0f) * step;

	y = draw_start;
	while (y <= draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;

		color = *(unsigned int *)(tex->data + (tex_y * tex->size_line + tex_x * (tex->bpp / 8)));

		*(unsigned int *)(game->data + (y * game->size_line + i * (game->bpp / 8))) = color;

		tex_pos += step;
		y++;
	}
}
