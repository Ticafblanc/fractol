#include <so_long.h>


int	check_wall_up(t_vars *vars)
{
	while (vars->map[vars->wall_y][vars->wall_x])
	{
		if (vars->map[vars->wall_y][vars->wall_x] == '1')
			vars->wall_x++;
		else
			return (-1);
	}
	vars->wall_y++;
	return (0);
}

int	check_wall_side(t_vars *vars)
{
	while (vars->map[vars->wall_y])
	{
		if (vars->map[vars->wall_y][0] == '1'
			&& vars->map[vars->wall_y][vars->wall_x] == '1')
			vars->wall_y++;
		else
			return (-1);
	}
	return (0);
}

int	check_wall_down(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->map[vars->wall_y][i])
	{
		if (vars->map[vars->wall_y][i] == '1')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	read_arg(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	**map_str;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd))
		i++;
	close(fd);
	vars->map = (char **)ft_calloc((i + 1), sizeof(char *));
	if (!vars->map)
		return (-1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	vars->map[i] = get_next_line(fd);
	while (vars->map[i++])
		vars->map[i] = get_next_line(fd);
	close(fd);	
	return (0);
}

int	check_map(char *argv, t_vars *vars)
{
	int	error;

	if (ft_check_extension(argv, ".ber") < 0)
	{ 
		vars->error_map = 6;
		return (-1);
	}
	if (read_arg(argv, vars) < 0)
	{
		vars->error_map = 7;
		return (-1);
	}
	if (check_wall_up(vars) < 0 || check_wall_side(vars) < 0
		|| check_wall_down(vars) < 0 || vars->wall_x == vars->wall_y)
		return (-1);
	if (check_caractere(vars) < 0)
		return (-1);	
	return (0);

	
	
}
