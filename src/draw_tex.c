/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:20:41 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 19:06:23 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static t_tex	*get_texture(t_game *game, t_dda *dda, t_ray *ray);
static float	get_wall_x(t_game *game, t_dda *dda, t_ray *ray);
static void		compute_line(int *line_h, int *start, int *end, float dist);
static void		draw_column(t_column *c, t_game *game, int col);

/*Orchestrates the texture drawing*/
void	draw_tex(t_game *game, t_dda *dda, t_ray *ray, int col)
{
	t_column	c;

	if (!game || !dda || !ray)
		return ;
	c.tex = get_texture(game, dda, ray);
	if (!c.tex)
		return ;
	c.wall_x = get_wall_x(game, dda, ray);
	compute_line(&c.line_height, &c.start, &c.end, dda->perp_dist);
	c.tex_x = (int)(c.wall_x * (float)c.tex->width);
	if ((dda->side == 0 && ray->ray_dir_x < 0) \
|| (dda->side == 1 && ray->ray_dir_y > 0))
		c.tex_x = c.tex->width - c.tex_x - 1;
	c.y = c.start;
	draw_column(&c, game, col);
}

/*Identifies what texture to print*/
static t_tex	*get_texture(t_game *game, t_dda *dda, t_ray *ray)
{
	if (dda->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (game->e_wall);
		return (game->w_wall);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (game->s_wall);
		return (game->n_wall);
	}
}

/*Identifies the point at which the ray touches the wall*/
static float	get_wall_x(t_game *game, t_dda *dda, t_ray *ray)
{
	float	wall_x;
	float	pos_x;
	float	pos_y;

	pos_x = game->player.x / (float)BLOCK;
	pos_y = game->player.y / (float)BLOCK;
	if (dda->side == 0)
		wall_x = pos_y + dda->perp_dist * ray->ray_dir_y;
	else
		wall_x = pos_x + dda->perp_dist * ray->ray_dir_x;
	return (wall_x - (floorf(wall_x)));
}

/*Calculates the parallelism between the wall and the texture*/
static void	compute_line(int *line_h, int *start, int *end, float dist)
{
	if (dist < 0.0001f)
		dist = 0.0001f;
	*line_h = (int)(HEIGHT / dist);
	if (*line_h < 1)
		*line_h = 1;
	*start = -(*line_h) / 2 + HEIGHT / 2;
	*end = *line_h / 2 + HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	if (*end > HEIGHT)
		*end = HEIGHT - 1;
}

/*Draw the actual column by calling put_pixel*/
static void	draw_column(t_column *c, t_game *game, int col)
{
	while (c->y <= c->end)
	{
		c->tex_y = (int)(((float)(c->y - HEIGHT / 2 + c->line_height / 2) \
/ (float)c->line_height) * (float)c->tex->height);
		if (c->tex_y < 0)
			c->tex_y = 0;
		if (c->tex_y >= c->tex->height)
			c->tex_y = c->tex->height - 1;
		c->tex_index = c->tex_y * c->tex->size_line + \
c->tex_x * c->tex->bpp / 8;
		c->color[0] = (unsigned char)c->tex->data[c->tex_index + 2];
		c->color[1] = (unsigned char)c->tex->data[c->tex_index + 1];
		c->color[2] = (unsigned char)c->tex->data[c->tex_index];
		put_pixel(game, col, c->y, c->color);
		c->y++;
	}
}
