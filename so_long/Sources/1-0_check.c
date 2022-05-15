
#include <so_long.h>

int	read_arg(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	vars->map = (char **)ft_calloc(i, sizeof(char *));
	if (!vars->map)
		return (-1);
	if (fill_map(argv, vars) < 0)
		return (-1);
	return (0);
}

int	fill_map(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		vars->map[i] = ft_strtrim(temp, "\n");
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	vars->map[i] = NULL;
	close(fd);
	return (0);
}

int	check_map(char *argv, t_vars *vars)
{
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
		|| check_wall_down(vars) < 0)
	{
		vars->error_map = 4;
		return (-1);
	}
	if (vars->wall_x == vars->wall_y)
	{
		vars->error_map = 5;
		return (-1);
	}
	if (check_caractere(vars) < 0)
		return (-1);
	return (0);
}
