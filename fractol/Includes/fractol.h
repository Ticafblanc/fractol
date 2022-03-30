/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:34 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/03/16 11:32:59 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../libft/includes/libft.h"

typedef struct save_mem
{
	int		arg;
}		t_mem;

	//0_fractol.c
void	ft_print_list_arg_valid(void);
void	ft_check_arg(int argc, char ***argv);

#endif
