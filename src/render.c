/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:00:35 by adpinhei          #+#    #+#             */
/*   Updated: 2026/04/02 18:50:33 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/structs.h"

static int	init_textures(t_game *game, t_img *img);
static int	load_textures(t_game *game, t_img *img);
static int	tex_addr(t_game *game);

int	init_game(t_game *game, t_img *img)
{
	if (!game || !img)
		return (ERR_GAME);
	init_player(&game->player, img);
	game->img_struct = img;
	game->map = img->map->grid;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, \
&game->size_line, &game->endian);
	if (init_textures(game, img))
		return (ERR_WALL_TEX);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

static int	init_textures(t_game *game, t_img *img)
{
	game->n_wall = malloc(sizeof(t_tex));
	game->s_wall = malloc(sizeof(t_tex));
	game->e_wall = malloc(sizeof(t_tex));
	game->w_wall = malloc(sizeof(t_tex));
	if (!game->n_wall || !game->s_wall || !game->e_wall || !game->w_wall)
	{
		printf("Unable to allocate t_tex\n");
		if (game->n_wall)
			free(game->n_wall);
		if (game->s_wall)
			free(game->s_wall);
		if (game->e_wall)
			free(game->e_wall);
		if (game->w_wall)
			free(game->w_wall);
		return (ERR_MALLOC);
	}
	if (load_textures(game, img))
		ft_exitgame(game);
	return (0);
}

static int	load_textures(t_game *game, t_img *img)
{
	game->n_wall->img = mlx_xpm_file_to_image(game->mlx, img->n_wall, \
&game->n_wall->width, &game->n_wall->height);
	game->s_wall->img = mlx_xpm_file_to_image(game->mlx, img->s_wall, \
&game->s_wall->width, &game->s_wall->height);
	game->e_wall->img = mlx_xpm_file_to_image(game->mlx, img->e_wall, \
&game->e_wall->width, &game->e_wall->height);
	game->w_wall->img = mlx_xpm_file_to_image(game->mlx, img->w_wall, \
&game->w_wall->width, &game->w_wall->height);
	if (!game->n_wall->img || !game->s_wall->img || \
!game->e_wall->img || !game->w_wall->img)
	{
		printf("Unable to load textures into memory\n");
		return (ERR_WALL_TEX);
	}
	if (tex_addr(game))
	{
		printf("Unable to store texture data address\n");
		return (ERR_WALL_TEX);
	}
	return (0);
}

static int	tex_addr(t_game *game)
{
	game->n_wall->data = mlx_get_data_addr(game->n_wall->img, &game->n_wall->bpp, \
&game->n_wall->size_line, &game->endian);
	game->s_wall->data = mlx_get_data_addr(game->s_wall->img, &game->s_wall->bpp, \
&game->s_wall->size_line, &game->endian);
	game->e_wall->data = mlx_get_data_addr(game->e_wall->img, &game->e_wall->bpp, \
&game->e_wall->size_line, &game->endian);
	game->w_wall->data = mlx_get_data_addr(game->w_wall->img, &game->w_wall->bpp, \
&game->w_wall->size_line, &game->endian);
	if (!game->n_wall->data || !game->s_wall->data || \
!game->e_wall->data || !game->w_wall->data)
		return (1);
	return (0);
}

int	ft_exitgame(t_game *game)
{
	if (!game)
		exit (0);
	if (game->img_struct)
		free_all(game->img_struct);
	if (game->n_wall)
	{
		mlx_destroy_image(game->mlx, game->n_wall->img);
		free(game->n_wall);
	}
	if (game->s_wall)
	{
		mlx_destroy_image(game->mlx, game->s_wall->img);
		free(game->s_wall);
	}
	if (game->e_wall)
	{
		mlx_destroy_image(game->mlx, game->e_wall->img);
		free(game->e_wall);
	}
	if (game->w_wall)
	{
		mlx_destroy_image(game->mlx, game->w_wall->img);
		free(game->w_wall);
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}
