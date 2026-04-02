/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:20:41 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/02 14:43:16 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static float	fixed_dist(float delta_x, float delta_y, t_game *game);

void	draw_background(t_game *game)
{
	int	y;
	int	x;
	// int	floor;
	// int	ceiling;

	// floor = 246524; //update to *game->img->floor
	// ceiling = 7026390;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < HEIGHT / 2)
		{
			x = -1;
			while (++x < WIDTH)
				put_pixel(game, x, y, game->img_struct->floor);
		}
		else
		{
			x = -1;
			while (++x < WIDTH)
				put_pixel(game, x, y, game->img_struct->ceiling);
		}
	}
}

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

void	draw_pov(t_game *game, float ray_x, float ray_y, int i)
{
	float		dist;
	float		height;
	t_player	*player;
	int			start_y;
	int			end;
	int			mock_color[3] = {0, 0, 255};

	player = &game->player;
	dist = fixed_dist(ray_x - player->x, ray_y - player->y, game);
	height = (BLOCK / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		if (player)
		put_pixel(game, i, start_y, mock_color);
		start_y++;
	}
}

static float	fixed_dist(float delta_x, float delta_y, t_game *game)
{
	float	angle;
	float	fix_dist;
	float	sqr_hipothenuse;

	angle = atan2(delta_y, delta_x) - game->player.angle;
	sqr_hipothenuse = delta_x * delta_x + delta_y * delta_y;
	fix_dist = sqrt(sqr_hipothenuse) * cos(angle);
	return (fix_dist);
}
