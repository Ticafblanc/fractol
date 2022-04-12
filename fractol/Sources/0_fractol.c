/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:04:06 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/31 13:33:37 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	main(int argc, char **argv)
{
	char *path;

	path = "../fractol/Sources/argv.txt";
	if (check_argv(argc, argv, path) == 1)
	{
		argv++;
		ft_launch_minilibx(argv);
		return (0);
	}
	return (0);
}

void	ft_launch_minilibx(char **argv)
{
	void	*mlx;
	void	*win;
	t_mem	save;
	int		i;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, argv[0]);
	save.img = mlx_new_image(mlx, 500, 500);
	save.addr = mlx_get_data_addr(save.img, &save.bpp, &save.l_l, &save.endian);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx);
	return (0);
}


