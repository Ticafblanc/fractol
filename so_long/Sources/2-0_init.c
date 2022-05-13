
#include <so_long.h>

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wall_x * TILES,
			vars->wall_y * TILES, "so_long");
}

void	init_t_img(t_vars *vars)
{
	vars->img = (t_img *)malloc(sizeof(t_img));
	vars->img->wall = (t_asset *)malloc(sizeof(t_asset));
	vars->img->emp = (t_asset *)malloc(sizeof(t_asset));
	vars->img->item = (t_asset *)malloc(sizeof(t_asset));
	vars->img->exit = (t_asset *)malloc(sizeof(t_asset));
	vars->img->enemy = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_down = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_up = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_left = (t_asset *)malloc(sizeof(t_asset));
	vars->img->player_right = (t_asset *)malloc(sizeof(t_asset));
	if (!vars->img || !vars->img->wall || !vars->img->emp || !vars->img->item
		|| !vars->img->exit || !vars->img->enemy || !vars->img->player_down 
		|| !vars->img->player_up || !vars->img->player_left || !vars->img->player_right)
		ft_exit_perror("init t_struct t_img failure", EXIT_FAILURE);
	init_wall(vars);
	init_exit(vars);
	init_item(vars);
	init_player(vars);
	init_enemy(vars);
}

int	init_game(t_vars *vars)
{
	init_window(vars);
	init_t_img(vars);
	put_game(vars);
	return (1);
}
