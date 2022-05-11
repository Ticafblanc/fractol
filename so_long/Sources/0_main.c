#include <so_long.h>

int	close(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(EXIT_SUCCESS);
}

int	action(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == ESC)
		close(game);
	if (keycode == UP)
		line--;
	if (keycode == DOWN)
		line++;
	if (keycode == LEFT)
		col--;
	if (keycode == RIGHT)
		col++;
	if (!game->end_game)
		move_player(game, line, col, keycode);
	return (1);
}

int	update(t_vars *vars)
{
	if (vars->end < 1)
		close(vars);
	put_game(vars);
	return (0);
}

t_vars	*init_t_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (vars = NULL);
	vars->player_side = DOWN;
	vars->end_game = 0;
	vars->steps = 0;
	vars->init_game = 0;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = init_t_vars();
	if (vars == NULL)
		ft_exit_perror("init t_struct t_vars failure", EXIT_FAILURE);
	if (argc != 2 || check_map(argv[1], vars) < 0)
		ft_exit_strerror(EINVAL, EXIT_FAILURE)
	if (init_game(vars) < 0)
		ft_exit_perror("init game failure", EXIT_FAILURE)
	mlx_hook(vars.win, ON_DESTROY, 0, close, (void *)&vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L << 0, action, (void *)&vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}
