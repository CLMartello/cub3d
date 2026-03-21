/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/21 18:22:53 by clumertz         ###   ########.fr       */
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
/*                                  Parser Func                               */
/* ************************************************************************** */

int     parse_cub_file(char *file);
void	valid_map(char *line, t_img *img);
void    start_map(char *line, t_img *img);
void    init_map(t_map *map);
void    init_img(t_img *img);
t_img   *init_struct(void);

/* Parse conf */

void	verify_conf(char *line, t_img *img);
void    parse_texture(char *line, t_img *img);
void    parse_rgb(char *line, int *rgb);

/* Parse map */

void	print_map(char **map);
int	    is_map(char *line);

/* ************************************************************************** */
/*                                  Str utils                                 */
/* ************************************************************************** */

char    *get_next_line(int fd);
char    *get_line(char *str);
int	    ft_isspace(char c);

/* ************************************************************************** */
/*                                  Error  Func                               */
/* ************************************************************************** */

void    ft_error(t_img  *img, int type_error);
void    free_all(t_img  *img);
void    free_map(t_map *map);
void    free_db_str(char **db_str);

#endif
