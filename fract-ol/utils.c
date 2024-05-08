/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:32:25 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/24 21:44:28 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || x >= width || y < 0 || y >= height)
        return ; // Avoid writing outside the image

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void clean(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
}

void choice (int x, t_data *mlx)
{
    if(x==1)
        draw_mandelbrot(mlx);
    else if(x==2)
    {
        t_complex c = {.real = -0.8, .imag = 0.156};
        draw_julia(mlx, c);
    }
}