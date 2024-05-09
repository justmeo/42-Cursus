/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:28 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/24 19:11:00 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(t_complex z, t_complex c)
{
    int n = 0;
    double real, imag;

    while (n < max_iter)
    {
        real = z.real * z.real - z.imag * z.imag + c.real;
        imag = 2 * z.real * z.imag + c.imag;
        z.real = real;
        z.imag = imag;
        if (z.real * z.real + z.imag * z.imag > 4)
        {
            return n;
        }
        n++;
    }
    return max_iter;
}

void draw_julia(t_data *mlx, t_complex c)
{
    int color;
    int x = 0;
    int y;
    double scaled_x, scaled_y;
    t_complex z;

    while (x < width)
    {
        y = 0;
        while (y < height)
        {
            scaled_x = map(x, 0, width, -1 * mlx->zoom_level + mlx->center_x, 0.5 * mlx->zoom_level + mlx->center_x);
            scaled_y = map(y, 0, height, -0.5 * mlx->zoom_level + mlx->center_y, 0.5 * mlx->zoom_level + mlx->center_y);
            z.real = scaled_x;
            z.imag = scaled_y;
            color = julia(z, c);
            // Change color to purple
            color = color % 256;
            color = color | color << 8 | color << 16 | color << 24;
            my_mlx_pixel_put(mlx, x, y, color);

            y++;
        }
        x++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}