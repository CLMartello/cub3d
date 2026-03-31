/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:19:08 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/31 18:51:13 by clumertz         ###   ########.fr       */
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
void	init_player(t_player *player, t_img *img);
void	clear_image(t_game *game);
void	put_pixel(t_game *game, int x, int y, int color);
void	draw_pov(t_game *game, float ray_x, float ray_y, int i);

bool	touch(float px, float py, t_game *game);
int	    ft_exitgame(t_game *game);
void	init_game(t_game *game, t_img *img);


/* ************************************************************************** */
/*                                  Parser Func                               */
/* ************************************************************************** */

void	verify_text(t_img *img);
void	verify_arg(char *line);
void	parse_cub_file(char *file, t_img *img);
void	start_map(t_img *img);
void	init_map(t_map *map);
void	init_img(t_img *img);
t_img	*init_struct(void);

/* Parse conf */

void	verify_conf(t_img *img);
void	parse_texture(t_img *img, int pos);
void	parse_rgb(t_img *img, int *rgb, int pos);

/* Parse map */

void	verify_map(t_img *img);
int     ft_fill(char **map, int y, int x, int height);
int		is_map(t_img *img);

/* ************************************************************************** */
/*                                  Str utils                                 */
/* ************************************************************************** */

int	    ft_strlen(char *c);
int	    ft_strchr(char *s, int c);
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
