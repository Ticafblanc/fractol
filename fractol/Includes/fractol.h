/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:34 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/31 13:27:55 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../libft/includes/libft.h"
# include "../../minilibx_opengl_20191021/mlx.h"

typedef struct save_mem
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_l;
	int		endian;
}		t_mem;

	//0_fractol.c
void	ft_check_arg(int argc, char ***argv);
void	ft_launch_minilibx(char **argv);

	//1_Command.c
int		deal_key(int key, void *param);
void	my_mlx_pixel_put(t_mem *save, int x, int y, int color);
#endif
