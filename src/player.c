/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:06:33 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/31 20:01:42 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	move_utils(t_game *game, float c_ang, float s_ang, int speed);

void	init_player(t_player *player, t_img *img)
{
	float	x;
	float	y;

	if (!player)
		return ;
	x = img->map->player_x;
	y = img->map->player_y;
	player->x = BLOCK * x;
	player->y = BLOCK * y;
	if (img->map->player_orientation == 'N')
		player->angle = (3 * PI) / 2;
	if (img->map->player_orientation == 'S')
		player->angle = PI / 2;
	if (img->map->player_orientation == 'W')
		player->angle = PI;
	if (img->map->player_orientation == 'E')
		player->angle = PI * 2;
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
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	move_utils(game, cos_angle, sin_angle, speed);
}

static void	move_or_collide(float new_x, float new_y, t_game *game)
{
	t_player	*player;
	float		prev_x;
	float		prev_y;

	player = &game->player;
	prev_x = player->x;
	prev_y = player->y;
	player->y = new_y;
	if (game->map[(int)(player->y / BLOCK)][(int)(player->x / BLOCK)] == '1')
		player->y = prev_y;
	player->x = new_x;
	if (game->map[(int)(player->y / BLOCK)][(int)(player->x / BLOCK)] == '1')
		player->x = prev_x;
	player = NULL;
}

static void	move_utils(t_game *game, float c_ang, float s_ang, int speed)
{
	t_player	*player;
	float		cos_speed;
	float		sin_speed;

	player = &game->player;
	cos_speed = c_ang * speed;
	sin_speed = s_ang * speed;
	if (game && game->player.key_up)
		move_or_collide(player->x + cos_speed, player->y + sin_speed, game);
	if (game && game->player.key_down)
		move_or_collide(player->x - cos_speed, player->y - sin_speed, game);
	if (game && game->player.key_left)
		move_or_collide(player->x + sin_speed, player->y - cos_speed, game);
	if (game && game->player.key_right)
		move_or_collide(player->x - sin_speed, player->y + cos_speed, game);
	player = NULL;
}

int	key_press(int keycode, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (keycode == XK_Escape)
		ft_exitgame(game);
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
