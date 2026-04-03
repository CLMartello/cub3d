/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:08:19 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 19:04:20 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/cub3d.h"

static void	init_dda(t_player *player, t_dda *dda, t_ray *ray);
static void	init_dda_utils(t_dda *dda, t_ray *ray);
static void	dda_core(t_game *game, t_dda *dda);

/*Performs the DDA algorithm and calls draw_tex*/
void	dda(t_game *game, t_ray *ray, int col)
{
	t_player	*player;
	t_dda		dda;

	if (!game)
		return ;
	player = &game->player;
	init_dda(player, &dda, ray);
	dda_core(game, &dda);
	if (dda.side == 0)
		dda.perp_dist = (dda.map_x - dda.pos_x + \
(1.0f - dda.step_x) / 2.0f) / ray->ray_dir_x;
	else
		dda.perp_dist = (dda.map_y - dda.pos_y + \
(1.0f - dda.step_y) / 2.0f) / ray->ray_dir_y;
	if (dda.perp_dist < 0.0001f)
		dda.perp_dist = 0.0001f;
	draw_tex(game, &dda, ray, col);
}

/*Makes the calculations for DDA based on the player's positions and 
the ray cast*/
static void	init_dda(t_player *player, t_dda *dda, t_ray *ray)
{
	if (!player || !dda || !ray)
		return ;
	dda->pos_x = player->x / (float)BLOCK;
	dda->pos_y = player->y / (float)BLOCK;
	dda->map_x = (int)dda->pos_x;
	dda->map_y = (int)dda->pos_y;
	if (fabsf(ray->ray_dir_x) < 1e-6f)
		dda->delta_dist_x = 1e30f;
	else
		dda->delta_dist_x = fabsf(1.0f / ray->ray_dir_x);
	if (fabsf(ray->ray_dir_y) < 1e-6f)
		dda->delta_dist_y = 1e30f;
	else
		dda->delta_dist_y = fabsf(1.0f / ray->ray_dir_y);
	dda->side = 0;
	init_dda_utils(dda, ray);
}

/*Calculates DDA'a side distance and each axis' step*/
static void	init_dda_utils(t_dda *dda, t_ray *ray)
{
	if (!dda || !ray)
		return ;
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (dda->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0f - dda->pos_x) * dda->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (dda->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0f - dda->pos_y) * dda->delta_dist_y;
	}
}

/*Figures out how rays are hitting walls*/
static void	dda_core(t_game *game, t_dda *dda)
{
	if (!game || !dda)
		return ;
	while (game->map[dda->map_y][dda->map_x] != '1')
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
	}
}
