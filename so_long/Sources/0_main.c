#include <so_long.h>

void	start_struct(t_game *game)
{
	game->side = 0;
	game->reset = 0;
	game->end_game = 0;
	game->steps = 0;
	game->init_game = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2 || check_map(argv[1]) < 0)
		ft_exit_strerror(EINVAL, EXIT_FAILURE)
	start_struct(&game);
	if (init_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_win, (void *)&game);
	mlx_hook(game.win, 2, 1L << 0, action, (void *)&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
