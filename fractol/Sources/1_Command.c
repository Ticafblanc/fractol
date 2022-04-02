/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_Command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:03:16 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/31 13:28:13 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	deal_key(int key, void *param)
{
	ft_putchar('x');
	return (0);
}

void	my_mlx_pixel_put(t_mem *save, int x, int y, int color)
{
	char	*dst;

	dst = save->addr + (y * save->l_l + x * (save->bpp / 8));
	*(unsigned int*)dst = color;
}

