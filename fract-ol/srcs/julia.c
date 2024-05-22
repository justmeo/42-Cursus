/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:28 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 03:25:06 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_complex c)
{
	int		n;
	double	real;
	double	imag;

	n = 0;
	while (n < MAX_ITER)
	{
		real = z.real * z.real - z.imag * z.imag + c.real;
		imag = 2 * z.real * z.imag + c.imag;
		z.real = real;
		z.imag = imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (n);
		n++;
	}
	return (MAX_ITER);
}

void	draw_julia(t_data *mlx, t_complex c)
{
	int			color;
	int			x;
	int			y;
	t_complex	z;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.real = -1.0 * mlx->zoom_level + mlx->center_x + (0.5
					* mlx->zoom_level - (-1.0 * mlx->zoom_level)) * ((double)x
					/ WIDTH);
			z.imag = -0.5 * mlx->zoom_level + mlx->center_y + (0.5
					* mlx->zoom_level - (-0.5 * mlx->zoom_level)) * ((double)y
					/ HEIGHT);
			color = julia(z, c);
			color = calculate_color(color, mlx);
			my_mlx_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
