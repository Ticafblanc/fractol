
#include <so_long.h>

void	*read_map(t_vars *vars, int line, int col)
{
	if (vars->game->map[line][col] == 'E')
		return (vars->img->exit->img);
	else if (vars->game->map[line][col] == 'C')
		return (vars->img->item->img);
	else if (vars->game->map[line][col] == 'V')
		return (vars->img->enemy->img);
	else if (vars->game->map[line][col] == '1')
		return (vars->img->wall->img);
	else if (vars->game->map[line][col] == '0')
		return (vars->img->emp->img);
	else
	{
		if (vars->player_side == DOWN)
			return (vars->img->player_down->img);
		else if (vars->player_side == UP)
			return (vars->img->player_up->img);
		else if (vars->player_side == RIGHT)
			return (vars->img->player_right->img);
		else
			return (vars->img->player_left->img);
	}
}

void	put_game(t_vars *vars)
{
	int		line;
	int		col;
	char	*str;

	line = 0;
	while (line < vars->game->line)
	{
		col = 0;
		while (col < vars->game->colum)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, read_map(vars, line, col), col * TILES, line * TILES);
			col++;
		}
		line++;
	}
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0xFFFF00, "Move :");
	str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFF00, str);
	free(str);
	if (vars->end_game)
		mlx_string_put(game->mlx, game->win, 150, 25, 0xFFFF00,"WIN esc to quit")
}
