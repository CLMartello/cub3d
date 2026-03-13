/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/12 20:05:03 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"

/* ************************************************************************** */
/*                                  Macros                                    */
/* ************************************************************************** */

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 0

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define PI 3.14159265359

/* ************************************************************************** */
/*                                  Test Func                                 */
/* ************************************************************************** */

/*
void init_player(t_player *player);
int key_release(int keycode, t_player *player);
int key_press(int keycode, t_player *player);
void move_player(t_player *player);*/

/* ************************************************************************** */
/*                                  Parser Func                                 */
/* ************************************************************************** */

int     parse_cub_file(char *file);
void    *verify_parse(char *line, t_img *img);
char    *parse_texture(char *line);
int     *parse_rgb(char *line);
void    valid_map(char *map);
char    *get_next_line(int fd);
char    *get_texture(char *str);

#endif
