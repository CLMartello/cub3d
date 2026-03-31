/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:35 by adpinhei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/26 19:52:08 by clumertz         ###   ########.fr       */
=======
/*   Updated: 2026/03/31 16:54:05 by adpinhei         ###   ########.fr       */
>>>>>>> rendering
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
	map[3] = "10000010101000001";
	map[4] = "10000000000000001";
	map[5] = "10000000000000001";
	map[6] = "10000000000000001";
	map[7] = "10000000000000001";
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

