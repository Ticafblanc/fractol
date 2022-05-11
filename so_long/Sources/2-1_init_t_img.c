
#include <so_long.h>

void	init_wall(t_vars *vars)
{
	vars->img->wall->img = mlx_xpm_file_to_image(vars->mlx, PATH_W, vars->img->wall->pos_x,
			vars->img->wall->pos_y);
	vars->img->wall->pixel = mlx_get_data_addr(vars->img->wall->img, vars->img->wall->bpp,
			vars->img->wall->line_size, vars->img->wall->endian);
	vars->img->emp->img = mlx_xpm_file_to_image(vars->mlx, PATH_E, vars->img->emp->pos_x,
			vars->img->emp->pos_y);
	vars->img->emp->pixel = mlx_get_data_addr(vars->img->emp->img, vars->img->emp->bpp,
			vars->img->emp->line_size, vars->img->emp->endian);
}

void	init_item(t_vars *vars)
{
	vars->img->item->img = mlx_xpm_file_to_image(vars->mlx, PATH_I, vars->img->item->pos_x,
			vars->img->item->pos_y);
	vars->img->item->pixel = mlx_get_data_addr(vars->img->item->img, vars->img->item->bpp,
			vars->img->item->line_size, vars->img->item->endian);
}

void	init_exit(t_vars *vars)
{
	vars->img->exit->img = mlx_xpm_file_to_image(vars->mlx, PATH_EX, vars->img->exit->pos_x,
			vars->img->exit->pos_y);
	vars->img->exit->pixel = mlx_get_data_addr(vars->img->exit->img, vars->img->exit->bpp,
			vars->img->exit->line_size, vars->img->exit->endian);
}

void	init_enemy(t_vars *vars)
{
	vars->img->enemy->img = mlx_xpm_file_to_image(vars->mlx, PATH_V, vars->img->enemy->pos_x,
			vars->img->enemy->pos_y);
	vars->img->enemy->pixel = mlx_get_data_addr(vars->img->enemy->img, vars->img->enemy->bpp,
			vars->img->enemy->line_size, vars->img->enemy->endian);
}

void	init_player(t_vars *vars)
{
	vars->img->player_down->img = mlx_xpm_file_to_image(vars->mlx, PATH_PD,
			vars->img->player_down->pos_x, vars->img->player_down->pos_y);
	vars->img->player_down->pixel = mlx_get_data_addr(vars->img->player_down->img,
			vars->img->player_down->bpp, vars->img->player_down->line_size,
			vars->img->player_down->endian);
	vars->img->player_up->img = mlx_xpm_file_to_image(vars->mlx, PATH_PT,
			vars->img->player_up->pos_x, vars->img->player_up->pos_y);
	vars->img->player_up->pixel = mlx_get_data_addr(vars->img->player_up->img,
			vars->img->player_up->bpp, vars->img->player_up->line_size,
			vars->img->player_up->endian);
	vars->img->player_left->img = mlx_xpm_file_to_image(vars->mlx, PATH_PL,
			vars->img->player_left->pos_x, vars->img->player_left->pos_y);
	vars->img->player_left->pixel = mlx_get_data_addr(vars->img->player_left->img,
			vars->img->player_left->bpp, vars->img->player_left->line_size,
			vars->img->player_left->endian);
	vars->img->player_right->img = mlx_xpm_file_to_image(vars->mlx, PATH_PR,
			vars->img->player_right->pos_x, vars->img->player_right->pos_y);
	vars->img->player_right->pixel = mlx_get_data_addr(vars->img->player_right->img,
			vars->img->player_right->bpp, vars->img->player_right->line_size,
			vars->img->player_right->endian);
}
