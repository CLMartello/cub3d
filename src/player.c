/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:06:33 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/30 16:20:33 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	move_utils(t_game *game, float c_ang, float s_ang, int speed);

void	init_player(t_player *player)
{
	if (!player)
		return ;
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

void	move_player(t_player *player, t_game *game)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 3;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	move_utils(game, cos_angle, sin_angle, speed);
}

static void	move_or_collide(float new_x, float new_y, t_game *game)
{
	if (!game)
		return ;
	if ((game->map[(int)new_y][(int)(new_x + 0.2)] != '1') && \
(game->map[(int)new_y][(int)(new_x - 0.2)] != '1'))
		game->player.x = new_x;
	if ((game->map[(int)(new_y + 0.2)][(int)new_x] != '1') && \
(game->map[(int)(new_y - 0.2)][(int)new_x] != '1'))
		game->player.y = new_y;
}

static void	move_utils(t_game *game, float c_ang, float s_ang, int speed)
{
	float		new_x;
	float		new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game && game->player.key_up)
	{
		new_x = game->player.x + c_ang * speed;
		new_y = game->player.y + s_ang * speed;
	}
	if (game && game->player.key_down)
	{
		new_x = game->player.x - c_ang * speed;
		new_y = game->player.y - s_ang * speed;
	}
	if (game && game->player.key_left)
	{
		new_x = game->player.x + s_ang * speed;
		new_y = game->player.y - c_ang * speed;
	}
	if (game && game->player.key_right)
	{
		new_x = game->player.x - s_ang * speed;
		new_y = game->player.y + c_ang * speed;
	}
	move_or_collide(new_x, new_y, game);
}

int	key_press(int keycode, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	if (keycode == XK_W || keycode == XK_w)
		player->key_up = true;
	if (keycode == XK_S || keycode == XK_s)
		player->key_down = true;
	if (keycode == XK_A || keycode == XK_a)
		player->key_left = true;
	if (keycode == XK_D || keycode == XK_d)
		player->key_right = true;
	if (keycode == XK_Left)
		player->left_rotate = true;
	if (keycode == XK_Right)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == XK_W || keycode == XK_w)
		player->key_up = false;
	if (keycode == XK_S || keycode == XK_s)
		player->key_down = false;
	if (keycode == XK_A || keycode == XK_a)
		player->key_left = false;
	if (keycode == XK_D || keycode == XK_d)
		player->key_right = false;
	if (keycode == XK_Left)
		player->left_rotate = false;
	if (keycode == XK_Right)
		player->right_rotate = false;
	return (0);
}
