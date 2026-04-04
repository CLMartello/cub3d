/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:35:15 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/03 18:35:39 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int *color)
{
	int	index;

	if (!game || x >= WIDTH || x < 0 || y >= HEIGHT || y < 0 || !color)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color[2];
	game->data[index + 1] = color[1];
	game->data[index + 2] = color[0];
}
