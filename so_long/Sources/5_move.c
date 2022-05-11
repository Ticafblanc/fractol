
#include <so_long.h>

void	check_side(t_vars *vars, int keycode)
{
	if (keycode == DOWN)
		vars->player_side = DOWN;
	else if (keycode == UP)
		vars->player_side = UP;
	else if (keycode == RIGHT)
		vars->player_side = RIGHT;
	else if (keycode == LEFT)
		vars->player_side = LEFT;
}

void	move_player(t_vars *vars, int line, int col, int key)
{
	int	y;
	int	x;

	y = game->map.player.y;
	x = game->map.player.x;
	if (vars->game->map[line][col] == 'C')
			game->map.check.collect--;
		;
		
	if (vars->game->map[line][col] == '1')
		return (-1);
	if (vars->game->map[line][col] == 'E')
		game->end_game = 1;
	if (vars->game->map[line][col] == 'E')
		return (-1);
	if (game->end_game)
		return (-1);
	if (vars->game->map[line][col] == 'V')
	{
		game->side = DOWN;
		reset(game);
		return (-1);
	}
	game->map.map[y][x] = '0'
	vars->game->map[line][col] = 'P';
	vars->game->player_y = line;
	vars->game->player_x = col;
	game->steps++;
	return (1);
}
