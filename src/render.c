/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:35 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/26 18:44:58 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

/*
char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "11111111111111111";
	map[1] = "10000000000000001";
	map[2] = "10000000000000001";
	map[3] = "10000010000000001";
	map[4] = "10010000000000001";
	map[5] = "10000000000000001";
	map[6] = "10001010000000001";
	map[7] = "10001000100100001";
	map[8] = "10000000000000001";
	map[9] = "11111111111111111";
	map[10] = NULL;
	return (map);
}*/

void	init_game(t_game *game)
{
	if (!game)
		return ;
	init_player(&game->player);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, \
&game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	ft_exitgame(t_game *game)
{
	if (game && game->mlx)
		mlx_loop_end(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	*img;

	if (argc != 2)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	img = init_struct();
	parse_cub_file(argv[1], img);
	init_game(&game);
	game.map = img->map->grid;
	mlx_hook(game.win, DestroyNotify, NoEventMask, &ft_exitgame, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	//free(game.map);
	return (0);
}
