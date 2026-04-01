/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:01:43 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/01 16:58:43 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

# define TRUE 1
# define FALSE 0

enum e_erro_identifier
{
	ERR_ARGS = 1,
	ERR_MALLOC,
	ERR_TEXT,
	ERR_RGB,
	ERR_MAP,
	ERR_GAME,
	ERR_WALL_TEX,
};

enum e_player_orientation_identifier
{
	NORTH = 78,
	SOUTH = 83,
	WEST = 87,
	EAST = 69,
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */



typedef struct s_map
{
	int		found;
	int		height;
	char	**grid;
	int		player_x;
	int		player_y;
	int		player_orientation;
}		t_map;

typedef struct s_img
{
	int		fd;
	char	*line;
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
	int		*floor;
	int		*ceiling;
	t_map	*map;
}		t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_tex
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
}	t_tex;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		**map;
	t_player	player;
	t_tex		*n_wall;
	t_tex		*s_wall;
	t_tex		*e_wall;
	t_tex		*w_wall;
	t_img		*img_struct;
}	t_game;

#endif
