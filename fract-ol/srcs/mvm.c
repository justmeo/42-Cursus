/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:22:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 03:46:16 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_scroll(int button, int x, int y, t_data *mlx)
{
	double	zoom_factor;
	double	mouse_x_scaled;
	double	mouse_y_scaled;

	zoom_factor = 1.1;
	mouse_x_scaled = (x - WIDTH / 2) / (0.5 * WIDTH);
	mouse_y_scaled = (y - HEIGHT / 2) / (0.5 * HEIGHT);
	if (button == 4)
		mlx->zoom_level *= zoom_factor;
	else if (button == 5)
		mlx->zoom_level /= zoom_factor;
	mlx->center_x += (mouse_x_scaled - mlx->center_x) / (mlx->zoom_level
			* zoom_factor);
	mlx->center_y += (mouse_y_scaled - mlx->center_y) / (mlx->zoom_level
			* zoom_factor);
	choice(mlx->fract, mlx);
	return (0);
}

void	move_view(int keycode, t_data *mlx)
{
	if (keycode == 13 || keycode == 126)
		mlx->center_y -= 0.1 / mlx->zoom_level;
	else if (keycode == 1 || keycode == 125)
		mlx->center_y += 0.1 / mlx->zoom_level;
	else if (keycode == 0 || keycode == 123)
		mlx->center_x -= 0.1 / mlx->zoom_level;
	else if (keycode == 2 || keycode == 124)
		mlx->center_x += 0.1 / mlx->zoom_level;
}

int	key_press(int keycode, t_data *mlx)
{
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
	{
		move_view(keycode, mlx);
		choice(mlx->fract, mlx);
	}
	else if (keycode == 49)
	{
		mlx->color_shift = (mlx->color_shift + 1) % 3;
		choice(mlx->fract, mlx);
	}
	else if (keycode == 53)
		clean(mlx);
	return (0);
}
