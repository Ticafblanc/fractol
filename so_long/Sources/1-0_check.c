
#include <so_long.h>

void	read_arg(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit_perror("Wrong path of the map", EXIT_FAILURE);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	printf("%d", i);
	close(fd);
	vars->map = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!vars->map)
		ft_exit_strerror(errno, EXIT_FAILURE);
	fill_map(argv, vars);
}

void	fill_map(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_exit_perror("Wrong path of the map", EXIT_FAILURE);
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
}

void	check_map(char *argv, t_vars *vars)
{
	read_arg(argv, vars);
	if (check_wall_up(vars) < 0 || check_wall_side(vars) < 0
		|| check_wall_down(vars) < 0)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("the map must not have closed walls",
			EXIT_FAILURE);
	}
	if (vars->wall_x == vars->wall_y)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("the card should only have a rectangular shape",
			EXIT_FAILURE);
	}
	if (check_caractere(vars) < 0)
	{
		ft_free_pp(vars->map);
		free(vars);
		ft_exit_perror("the map need at least 1 collect item, 1 exit and just 1 player", EXIT_FAILURE);
	}
}
