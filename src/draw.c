/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:17:27 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 19:36:17 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	draw_square(t_game *game, int color, int size, int x, int y);
static void	draw_map(t_game *game);
static void	draw_line(t_player *player, t_game *game, float start_x, int i);

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	if (!game)
		return (-1);
	player = &game->player;
	move_player(player);
	clear_image(game);
	draw_square(game, 0x00FF00, 10, player->x, player->y);
	draw_map(game);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

static void	draw_square(t_game *game, int color, int size, int x, int y)
{
	return ;//comment
	for (int i = 0; i < size; i++)
		put_pixel(game, x + i, y, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x, y + i, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x + size, y + i, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x + i, y + size, color);
}

static void	draw_map(t_game *game)
{
	return ;//comment
	int	color;
	int	x;
	int	y;

	color = 0x0000FF;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				draw_square(game, color, BLOCK, x * BLOCK, y * BLOCK);
		}
	}
}

static void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!touch(ray_x, ray_y, game))
	{
		//put_pixel(game, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	draw_pov(game, ray_x, ray_y, i);
}
