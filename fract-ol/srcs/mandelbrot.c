/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:12:36 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 03:19:40 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			n;
	double		real;
	double		imag;

	z.real = 0;
	z.imag = 0;
	n = 0;
	while (n < MAX_ITER)
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
	return (MAX_ITER);
}

void	draw_mandelbrot(t_data *mlx)
{
	int			x;
	int			y;
	int			color;
	int			m;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx->c.real = -1.0 * mlx->zoom_level + mlx->center_x + (0.5
					* mlx->zoom_level - (-1.0 * mlx->zoom_level)) * ((double)x
					/ WIDTH);
			mlx->c.imag = -0.5 * mlx->zoom_level + mlx->center_y + (0.5
					* mlx->zoom_level - (-0.5 * mlx->zoom_level)) * ((double)y
					/ HEIGHT);
			m = mandelbrot(mlx->c);
			color = calculate_color(m, mlx);
			my_mlx_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
