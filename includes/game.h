/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/31 16:53:26 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"
# include "cub3d.h"

/* ************************************************************************** */
/*                                  Macros                                    */
/* ************************************************************************** */

# define WIDTH 1200
# define HEIGHT 800
# define BLOCK 64

# define PI 3.14159265359

/* ************************************************************************** */
/*                             Render Functions                               */
/* ************************************************************************** */

int		key_release(int keycode, t_player *player);
int		key_press(int keycode, t_game *game);
int		draw_loop(t_game *game);

void	move_player(t_player *player, t_game *game);
void	init_player(t_player *player);
void	clear_image(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
void	draw_pov(t_game *game, float ray_x, float ray_y, int i);

bool	touch(float px, float py, t_game *game);

#endif