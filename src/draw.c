/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:17:27 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 17:11:51 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	init_ray(t_player *p, t_ray *ray);

int	draw_loop(t_game *game)
{
	t_player	*p;
	t_ray		ray;
	int			i;

	if (!game)
		return (-1);
	p = &game->player;
	init_ray(p, &ray);
	move_player(p, game);
	draw_background(game);
	i = 0;
	while (i < WIDTH)
	{
		ray.camera = 2.0f * i / (float)WIDTH - 1.0f;
		ray.ray_dir_x = ray.dir_x + ray.plane_x * ray.camera;
		ray.ray_dir_y = ray.dir_y + ray.plane_y * ray.camera;
		dda(game, &ray, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->img_struct || !game->img_struct->floor || \
!game->img_struct->ceiling)
		return ;
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

static void	init_ray(t_player *p, t_ray *ray)
{
	ray->dir_x = cosf(p->angle);
	ray->dir_y = sinf(p->angle);
	ray->plane_x = -(ray->dir_y) * 0.66f;
	ray->plane_y = ray->dir_x * 0.66f;
}
