
#include <so_long.h>

int	check_caractere(t_vars *vars)
{
	int	x;
	int	y;

	
	y = 1;
	while (y != vars->wall_y)
	{
		x = 1;
		while (x != vars->wall_x)
		{
			if (check_cara(vars, x, y) >= 0)
				x++;
			else
				return (-1);
		}
		y++;
	}
	if (vars->end_game > 0 && vars->item > 0
		&& vars->steps == 1)
		{
			vars->end_game = 0;
			vars->steps = 0;
			return (0);
		}
	return (-1);
}

int	check_cara(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'E')
	{
		vars->end_game++;
		return (0);
	}
	else if (vars->map[y][x] == 'C')
	{
		vars->item++;
		return (0);
	}
	else if (vars->map[y][x] == 'v')
		return (0);
	else if (vars->map[y][x] == '0')
		return (0);
	else if (vars->map[y][x] == '1')
		return (0);
	else if (vars->map[y][x] == 'p')
	{
		vars->steps++;
		vars->player_x = x;
		vars->player_y = y;
		return (0);
	}
	return (-1);
}