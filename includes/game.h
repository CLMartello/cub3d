/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 17:05:47 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"
# include "cub3d.h"

/* ************************************************************************** */
/*                                  Macros                                    */
/* ************************************************************************** */

# define WIDTH 816 //BLOCK * map_size
# define HEIGHT 528 // BLOCK * map_length
# define BLOCK 48

# define PI 3.14159265359

/* ************************************************************************** */
/*                             Render Functions                               */
/* ************************************************************************** */

int		key_release(int keycode, t_player *player);
int		key_press(int keycode, t_game *game);
int		draw_loop(t_game *game);

void	move_player(t_player *player);
void	init_player(t_player *player);
void	clear_image(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);

bool	touch(float px, float py, t_game *game);

#endif