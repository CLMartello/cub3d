/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:10:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/02 19:19:50 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_game(char **map)
{
	t_game	*game;
	ft_init_game(&game, map);
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, &ft_exitgame, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_keypress, game);
	mlx_loop(game->mlx);
}

int	main()
{
	char	map[5][5] = {
		"11111",
		"10001",
		"10N01",
		"10001",
		"11111"
	};
	ft_game(map);
}