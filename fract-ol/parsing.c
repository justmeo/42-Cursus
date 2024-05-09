/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:32:32 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 00:25:27 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_input(char *input, t_data *mlx)
{
	if (strcmp(input, "m") == 0 || strcmp(input, "M") == 0)
	{
		mlx->fract = 1; // Mandelbrot
	}
	else if (strcmp(input, "j") == 0 || strcmp(input, "J") == 0)
	{
		mlx->fract = 2; // Julia
	}
	else
	{
		print_fractal_options();
		exit(1);
	}
}

void arg(t_data *mlx,char *av1,char *av2,char *av3,int ac)
{
    if (ac != 2 && mlx->fract != 2)
	{
		fprintf(stderr, "Usage: %s <M for Mandelbrot, J for Julia>\n", av1);
		clean(mlx);
	}
    else if(ac == 2)
       {
        mlx->c.real = -0.8;
        mlx->c.imag = 0.156;
       }
    else if(ac != 4)
       {
         print_fractal_options();
         clean(mlx);
       }
    else
    {
        mlx->c.real=ft_atof(av2);
        mlx->c.imag=ft_atof(av3);
    }
}
