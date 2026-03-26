/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/26 20:36:51 by clumertz         ###   ########.fr       */
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
void	draw_pov(t_game *game, float ray_x, float ray_y, int i);

bool	touch(float px, float py, t_game *game);
int	    ft_exitgame(t_game *game);
void	init_game(t_game *game);


/* ************************************************************************** */
/*                                  Parser Func                               */
/* ************************************************************************** */

void	parse_cub_file(char *file, t_img *img);
void	valid_map(char *line, t_img *img);
void	start_map(char *line, t_img *img);
void	init_map(t_map *map);
void	init_img(t_img *img);
t_img	*init_struct(void);

/* Parse conf */

void	verify_conf(char *line, t_img *img);
void	parse_texture(char *line, t_img *img);
void	parse_rgb(char *line, int *rgb);

/* Parse map */

void	verify_map(t_img *img);
int     ft_fill(char **map, int y, int x, int height);
void	verify_player(char player, t_img *img);
int		is_map(char *line, t_img *img);

/* ************************************************************************** */
/*                                  Str utils                                 */
/* ************************************************************************** */

int	    ft_strncmp(char *s1, char *s2, int n);
char	*get_next_line(int fd);
char	*get_line(char *str);
int		ft_isspace(char c);

/* ************************************************************************** */
/*                                  Error  Func                               */
/* ************************************************************************** */

void	ft_error(t_img *img, int type_error);
void	free_all(t_img *img);
void	free_map(t_map *map);
void	free_db_str(char **db_str);



void	print_parse(t_img *img);

#endif
