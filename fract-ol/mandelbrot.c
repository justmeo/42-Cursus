/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:12:36 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/05 03:34:13 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data c, int max_iter)
{
	t_data	z;
	int		n;
	double	real;
	double	imag;

	z.real = 0;
	z.imag = 0;
	for (n = 0; n < max_iter; n++)
	{
		real = z.real * z.real - z.imag * z.imag + c.real;
		imag = 2 * z.real * z.imag + c.imag;
		z.real = real;
		z.imag = imag;
		if (z.real * z.real + z.imag * z.imag > 4)
		{
			return (n);
		}
	}
	return (max_iter);
}

void	draw_mandelbrot(t_data *mlx, int width, int height, int max_iter)
{
	int	color;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			// Map the pixel coordinates to a complex number
			t_data c = {
				.real = (double)x / width * 3.5 - 2.5,
				.imag = (double)y / height * 2.0 - 1.0};
			// Apply the mandelbrot function to the complex number
			color = mandelbrot(c, max_iter);
			// Draw the pixel
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		}
	}
}
