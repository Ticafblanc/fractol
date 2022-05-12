#include <so_long.h>

int	close(t_vars *vars)
{
	free_map(vars);
	exit(EXIT_SUCCESS);
}

int	read_key(int keycode, t_vars *vars)
{
	int	line;
	int	col;

	if (vars->end_game == 1 || (keycode != ESC && keycode != UP 
		&& keycode != DOWN && keycode != LEFT && keycode != RIGHT))
		return (0);
	line = vars->player_y;
	col = vars->player_x;
	if (keycode == ESC)
		close(vars);
	else if (keycode == UP)
		line--;
	else if (keycode == DOWN)
		line++;
	else if (keycode == LEFT)
		col--;
	else if (keycode == RIGHT)
		col++;
	check_side(vars, keycode);
	if (vars->map[line][col] != '1')
		check_move (vars, line, col, keycode);
	return (0);
}

int	update(t_vars *vars)
{
	put_game(vars);
	return (0);
}

t_vars	*init_t_vars(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		ft_exit_perror("init t_struct t_vars failure", EXIT_FAILURE);
	vars->error_map = 0;
	vars->wall_x = 0;
	vars->wall_y = 0;
	vars->enemy_win = 0;
	vars->end_game = 0;
	vars->steps = 0;
	vars->player_side = DOWN;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->item = 0;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = init_t_vars();	
	if (argc != 2 || check_map(argv[1], vars) < 0)
		ft_exit_strerror(put_error_arg(vars->error_map), EXIT_FAILURE);
	if (init_game(vars) < 0)
		ft_exit_perror("init game failure", EXIT_FAILURE);
	mlx_hook(vars->win, ON_DESTROY, 0, close, (void *)&vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, read_key, (void *)&vars);
	mlx_loop_hook(vars->mlx, update, &vars);
	mlx_loop(vars->mlx);
}
