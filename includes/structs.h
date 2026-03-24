/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:01:43 by adpinhei          #+#    #+#             */
/*   Updated: 2026/03/24 21:29:00 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

enum e_erro_identifier
{
	ERR_OPEN = 1,
	ERR_MALLOC,
	ERR_ACCESS,
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

#endif
