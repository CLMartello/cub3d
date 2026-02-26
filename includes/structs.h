/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:01:43 by adpinhei          #+#    #+#             */
/*   Updated: 2026/02/26 16:15:08 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

typedef struct s_img
{
	int		floor[3]; //array with RGB values. Same for ceiling
	int		ceiling[3];
	char	*n_wall; //path-to-texture. Same for the following
	char	*s_wall;
	char	*e_wall;
	char	*w_wall;
}	t_img;

typedef struct s_game
{
	char	**map;
	char	player; //player initial orientation, i.e. N,S,E or W
	t_img	textures; //struct to hold the images
}	t_game;

#endif