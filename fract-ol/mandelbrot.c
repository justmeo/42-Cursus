/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:12:36 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/24 21:46:30 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_complex c)
{
    t_complex   z;
    int      n;
    double   real;
    double   imag;

    z.real = 0;
    z.imag = 0;
    n = 0;
    while (n < max_iter)
    {
        real = z.real * z.real - z.imag * z.imag + c.real;
        imag = 2 * z.real * z.imag + c.imag;
        z.real = real;
        z.imag = imag;
        if (z.real * z.real + z.imag * z.imag > 4)
        {
            return (n);
        }
        n++;
    }
    return (max_iter);
}

double map(int value, int start1, int stop1, double start2, double stop2) 
{
	double me ;
	
	me = start2 + (stop2 - start2) * ((value - start1) / (double)(stop1 - start1));
    return me;
}

unsigned int calculate_color(int m, t_data *mlx) {
    unsigned int color;
    if (m == max_iter) // if the point is in the Mandelbrot set, color it black
        color = 0x000000;
    else if (mlx->color_shift == 0)
        color = ((m % 8) * 32) << 16; // Purple
    else if (mlx->color_shift == 1)
        color = ((m % 8) * 32) << 8; // Green
    else
        color = ((m % 8) * 32); // Blue

    return color;
}

void draw_mandelbrot(t_data *mlx)
{
    int x = 0;
    int y;
    int color;
    t_complex c;
    

    while (x < width)
    {
        y = 0;
        while (y < height)
        {
            // Map the pixel coordinates to a complex number
            c.real = map(x, 0, width, -1.0 * mlx->zoom_level + mlx->center_x, 0.5 * mlx->zoom_level + mlx->center_x);
            c.imag = map(y, 0, height, -0.5 * mlx->zoom_level + mlx->center_y, 0.5 * mlx->zoom_level + mlx->center_y);
            // Compute the color of the pixel
            int m = mandelbrot(c);
            color = calculate_color(m, mlx);


            // Draw the pixel
            my_mlx_pixel_put(mlx, x, y, color);

            y++;
        }
        x++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

