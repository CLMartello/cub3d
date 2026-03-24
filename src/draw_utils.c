/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:20:41 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 17:28:08 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static float	distance(float x, float y);

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(game, x, y, 0.000000);
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

void	put_pixel(t_game *game, int x, int y, int color)
{
	int	index;

	if (!game || x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_pov(t_game *game, float ray_x, float ray_y, int i)
{
	float		dist;
	float		height;
	t_player	*player;
	int			start_y;
	int			end;

	player = &game->player;
	dist = distance(ray_x - player->x, ray_y - player->y);
	height = (BLOCK / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		put_pixel(game, i, start_y, 0x0000FF);
		start_y++;
	}
}

static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}
