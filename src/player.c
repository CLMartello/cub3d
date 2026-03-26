/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:06:33 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 16:46:07 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	move_utils(t_player *player, float c_ang, float s_ang, int speed);

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

void	move_player(t_player *player)
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
	move_utils(player, cos_angle, sin_angle, speed);
}

static void	move_utils(t_player *player, float c_ang, float s_ang, int speed)
{
	if (player->key_up)
	{
		player->x += c_ang * speed;
		player->y += s_ang * speed;
	}
	if (player->key_down)
	{
		player->x -= c_ang * speed;
		player->y -= s_ang * speed;
	}
	if (player->key_left)
	{
		player->x += s_ang * speed;
		player->y -= c_ang * speed;
	}
	if (player->key_right)
	{
		player->x -= s_ang * speed;
		player->y += c_ang * speed;
	}
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
