
#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	*img;

	if (argc != 2)
		ft_error(NULL, ERR_ARGS);
	img = init_struct();
	parse_cub_file(argv[1], img);
    //print_parse(img);
	init_game(&game);
	game.map = img->map->grid;
	mlx_hook(game.win, DestroyNotify, NoEventMask, &ft_exitgame, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	free(game.map);
    free_all(img);
	return (0);
}