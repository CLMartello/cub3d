/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:17:27 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/02 19:17:43 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

//static void	draw_line(t_player *player, t_game *game, float start_x, int i);

void	draw_line(t_game *game, float ray_dir_x, float ray_dir_y, int i)
{
	t_player	*player;
	float		pos_x;
	float		pos_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			side;
	float		perp_dist;

	player = &game->player;
	pos_x = player->x / (float)BLOCK;
	pos_y = player->y / (float)BLOCK;
	map_x = (int)pos_x;
	map_y = (int)pos_y;

	if (fabsf(ray_dir_x) < 1e-6f)
		delta_dist_x = 1e30f;
	else
		delta_dist_x = fabsf(1.0f / ray_dir_x);

	if (fabsf(ray_dir_y) < 1e-6f)
		delta_dist_y = 1e30f;
	else
		delta_dist_y = fabsf(1.0f / ray_dir_y);

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0f - pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0f - pos_y) * delta_dist_y;
	}

	side = 0;
	while (game->map[map_y][map_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
	}

	if (side == 0)
		perp_dist = (map_x - pos_x + (1.0f - step_x) / 2.0f) / ray_dir_x;
	else
		perp_dist = (map_y - pos_y + (1.0f - step_y) / 2.0f) / ray_dir_y;

	if (perp_dist < 0.0001f)
		perp_dist = 0.0001f;

	draw_pov(game, perp_dist, side, ray_dir_x, ray_dir_y, i);
}

int	draw_loop(t_game *game)
{
	t_player	*p;
	int			i;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		camera_x;
	float		ray_dir_x;
	float		ray_dir_y;

	if (!game)
		return (-1);
	p = &game->player;
	move_player(p, game);
	draw_background(game);

	dir_x = cosf(p->angle);
	dir_y = sinf(p->angle);

	/* 0.66f gives a classic ~66° FOV */
	plane_x = -dir_y * 0.66f;
	plane_y = dir_x * 0.66f;

	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2.0f * i / (float)WIDTH - 1.0f;
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_x;
		draw_line(game, ray_dir_x, ray_dir_y, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

// int	draw_loop(t_game *game)
// {
// 	t_player	*player;
// 	float		fraction;
// 	float		start_x;
// 	int			i;

// 	if (!game)
// 		return (-1);
// 	player = &game->player;
// 	move_player(player, game);
// 	draw_background(game);
// 	fraction = PI / 3 / WIDTH;
// 	start_x = player->angle - PI / 6;
// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		draw_line(player, game, start_x, i);
// 		start_x += fraction;
// 		i++;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	return (0);
// }

// static void	draw_line(t_player *player, t_game *game, float start_x, int i)
// {
// 	float	cos_angle;
// 	float	sin_angle;
// 	float	ray_x;
// 	float	ray_y;

// 	cos_angle = cos(start_x);
// 	sin_angle = sin(start_x);
// 	ray_x = player->x;
// 	ray_y = player->y;
// 	while (!touch(ray_x, ray_y, game))
// 	{
// 		ray_x += cos_angle;
// 		ray_y += sin_angle;
// 	}
// 	draw_pov(game, ray_x, ray_y, i);
// }
