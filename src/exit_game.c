/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:35 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 18:53:16 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static void	ft_clean_walls(t_game *game);

int	ft_exitgame(t_game *game)
{
	if (!game)
		exit (0);
	if (game->img_struct)
	{
		free_all(game->img_struct);
	}
	ft_clean_walls(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}

static void	ft_clean_walls(t_game *game)
{
	if (!game)
		return ;
	if (game->n_wall)
	{
		mlx_destroy_image(game->mlx, game->n_wall->img);
		free(game->n_wall);
	}
	if (game->s_wall)
	{
		mlx_destroy_image(game->mlx, game->s_wall->img);
		free(game->s_wall);
	}
	if (game->e_wall)
	{
		mlx_destroy_image(game->mlx, game->e_wall->img);
		free(game->e_wall);
	}
	if (game->w_wall)
	{
		mlx_destroy_image(game->mlx, game->w_wall->img);
		free(game->w_wall);
	}
}
