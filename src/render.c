/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:35 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 16:03:08 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

void	move_player(t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 5;
	angle_speed = 0.1;
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
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
}

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
	return 0;
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
	return 0;
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

void	draw_square(t_game *game, int color, int size, int x, int y)
{
	for (int i = 0; i < size; i++)
		put_pixel(game, x + i, y, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x, y + i, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x + size, y + i, color);
	for (int i = 0; i < size; i++)
		put_pixel(game, x + i, y + size, color);
}

void	draw_map(t_game *game)
{
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

char	**get_map(void)
{
	char	**map = malloc(sizeof(char *) * 11);
	map[0] = "11111111111111111";
	map[1] = "10000000000000001";
	map[2] = "10000000000000001";
	map[3] = "10000010000000001";
	map[4] = "10010000000000001";
	map[5] = "10000000100100001";
	map[6] = "10000000100100001";
	map[7] = "10001000101100001";
	map[8] = "10000000000000001";
	map[9] = "11111111111111111";
	map[10] = NULL;
	return (map);
}

void	init_game(t_game *game)
{
	if (!game)
		return ;
	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp,\
		 &game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

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
	int	x = px / BLOCK;
	int	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	draw_line(t_player *player, t_game *game, float start_x)
{
	float	cos_angle = cos(start_x);
	float	sin_angle = sin(start_x);
	float	ray_x = player->x;
	float	ray_y = player->y;

	while (!touch(ray_x, ray_y, game))
	{
		put_pixel(game, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;

	if (!game)
		return -1;
	player = &game->player;
	move_player(player);
	clear_image(game);
	draw_square(game, 0x00FF00, 10, player->x, player->y);
	draw_map(game);
	float	fraction = PI / 3 / WIDTH;
	float	start_x = player->angle - PI / 6;
	int		i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, start_x);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return 0;
}

int	ft_exitgame(t_game *game)
{
	if (game && game->mlx)
		mlx_loop_end(game->mlx);
	return 0;
}

int	main(void)
{
	t_game	game;

	init_game(&game);
	mlx_hook(game.win, DestroyNotify, NoEventMask, &ft_exitgame, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	free(game.map);
	return 0;
}