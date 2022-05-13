
#include <so_long.h>

void	free_map(t_vars *vars)
{
	free (vars->img->wall);
	free (vars->img->emp);
	free (vars->img->item);
	free (vars->img->exit);
	free (vars->img->enemy);
	free (vars->img->player_down);
	free (vars->img->player_up);
	free (vars->img->player_left);
	free (vars->img->player_right);
	free (vars->img);
	ft_free_pp(vars->map);
	free(vars);
}

int	put_error_arg(int error)
{
	if (error == 1)
		ft_putstr_fd("the map need at least 1 collect item", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("the map need at least 1 exit", STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("the map must have just 1 player", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("the map must not have closed walls", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("the card should only have a rectangular shape", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("Wrong extension of the map", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("Wrong path of the map", STDERR_FILENO);
	else
		ft_putstr_fd("just one map !!", STDERR_FILENO);
	return (EINVAL);
}

