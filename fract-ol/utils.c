/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:32:25 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 00:17:52 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= width || y < 0 || y >= height)
		return ; // Avoid writing outside the image
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clean(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(0);
}

unsigned int	calculate_color(int m, t_data *mlx)
{
	unsigned int	color;

	if (m == max_iter) // if the point is in the Mandelbrot set, color it black
		color = 0x000000;
	else if (mlx->color_shift == 0)
		color = ((m % 8) * 32) << 16; // Purple
	else if (mlx->color_shift == 1)
		color = ((m % 8) * 32) << 8; // Green
	else
		color = ((m % 8) * 32); // Blue
	return (color);
}

void	choice(int x, t_data *mlx)
{
	if (x == 1)
		draw_mandelbrot(mlx);
	else if (x == 2)
	{
		draw_julia(mlx, mlx->c);
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		hasDecimal;
	int		sign;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	hasDecimal = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str++ == '.')
		while (*str >= '0' && *str <= '9')
			result += (*str++ - '0') * fraction, fraction *= 0.1;
	return (result * sign);
}
