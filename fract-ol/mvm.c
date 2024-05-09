/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:22:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/09 22:38:06 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_scroll(int button, int x, int y, t_data *mlx)
{
    double zoom_factor = 1.1;
    double mouse_x_scaled = (x - width / 2) / (0.5 * width);
    double mouse_y_scaled = (y - height / 2) / (0.5 * height);

    // Increase or decrease the zoom level based on the scroll direction
    if (button == 4) // Scroll up
        mlx->zoom_level *= zoom_factor;
    else if (button == 5) // Scroll down
        mlx->zoom_level /= zoom_factor;

    // Adjust the center of the view based on the mouse position
    mlx->center_x += (mouse_x_scaled - mlx->center_x) / (mlx->zoom_level * zoom_factor);
    mlx->center_y += (mouse_y_scaled - mlx->center_y) / (mlx->zoom_level * zoom_factor);

    // Redraw the Mandelbrot set with the new zoom level and center
    choice(mlx->fract, mlx);
    return (0);
}

int key_press(int keycode, t_data *mlx)
{
    if (keycode == 13) // 119 is the ASCII value for 'w'
    {
        mlx->center_y -= 0.1 / mlx->zoom_level; // Move up
            choice(mlx->fract, mlx);
    }
    else if (keycode == 1) // 115 is the ASCII value for 's'
    {
        mlx->center_y += 0.1 / mlx->zoom_level; // Move down
            choice(mlx->fract, mlx);
    }
    else if (keycode == 0) // 97 is the ASCII value for 'a'
    {
        mlx->center_x -= 0.1 / mlx->zoom_level; // Move left
            choice(mlx->fract, mlx);
    }
    else if (keycode == 2) // 100 is the ASCII value for 'd'
    {
        mlx->center_x += 0.1 / mlx->zoom_level; // Move right
            choice(mlx->fract, mlx);
    }
    else if (keycode == 49) // 32 is the ASCII value for 'space'
    {
        mlx->color_shift = (mlx->color_shift + 1) % 3; // Cycle through 3 different color schemes
        choice(mlx->fract, mlx);
    }
    else if (keycode == 53)
        clean(mlx);

    return (0);
}


