/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:32:53 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 04:55:02 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship(t_complex c)
{
	t_complex	z;
	int			iteration;
	double		temp;

	iteration = 0;
	while (iteration < MAX_ITER)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		if (z.real * z.imag < 0)
			z.imag = -2.0 * z.real * z.imag + c.imag;
		else
			z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			break ;
		iteration++;
	}
	return (iteration);
}

void	draw_burningship(t_data *mlx)
{
	int	x;
	int	y;
	int	color;

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
			color = burningship(mlx->c);
			color = calculate_color(color, mlx);
			my_mlx_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
