/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:01:43 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/26 19:58:00 by clumertz         ###   ########.fr       */
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
	ERR_OPEN,
	ERR_MALLOC,
	ERR_TEXT,
	ERR_RGB,
	ERR_MAP,
};

enum e_player_orientation_identifier
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST,
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
}	t_game;

#endif
