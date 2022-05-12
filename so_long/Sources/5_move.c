
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

void	check_move(t_vars *vars, int line, int col, int key)
{
	int	y;
	int	x;

	y = vars->map.player.y;
	x = game->map.player.x;
	if (vars->map[line][col] == 'C')
		vars->check_collect--;		
	if (vars->map[line][col] == 'E')
		vars->end_game = 1;
	if (vars->map[line][col] == 'V')
		vars->enemy_win = 1;
	game->map.map[y][x] = '0';
	vars->map[line][col] = 'P';
	vars->player_y = line;
	vars->player_x = col;
	game->steps++;
	return (1);
}
