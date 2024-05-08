/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:22:07 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/24 21:19:54 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void zoom(t_data *mlx, double zoom) 
{
    
    mlx->center_x = mlx->min_x + (mlx->max_x - mlx->min_x) / 2;
    mlx->center_y = mlx->min_y + (mlx->max_y - mlx->min_y) / 2;
    
    mlx->min_x = mlx->center_x - (mlx->center_x - mlx->min_x) * zoom;
    mlx->max_x = mlx->center_x + (mlx->max_x - mlx->center_x) * zoom;
    mlx->min_y = mlx->center_y - (mlx->center_y - mlx->min_y) * zoom;
    mlx->max_y = mlx->center_y + (mlx->max_y - mlx->center_y) * zoom;
}

int handle_scroll(int button, int x, int y, t_data *mlx)
{

    // Increase or decrease the zoom level based on the scroll direction
    if (button == 4) // Scroll up
        mlx->zoom_level *= 1.1;
    else if (button == 5) // Scroll down
        mlx->zoom_level /= 1.1;

    // Adjust the center of the view based on the mouse position
    mlx->center_x = (x - width / 2) / (0.5 * mlx->zoom_level * width) ;
    mlx->center_y = (y - height / 2) / (0.5 * mlx->zoom_level * height) ;

    // Redraw the Mandelbrot set with the new zoom level and center
    choice(mlx->fract, mlx);
    return (0);
}

int key_press(int keycode, t_data *mlx)
{
    if (keycode == 119) // 119 is the ASCII value for 'w'
    {
        mlx->center_y -= 0.1 / mlx->zoom_level; // Move up
            choice(mlx->fract, mlx);
    }
    else if (keycode == 115) // 115 is the ASCII value for 's'
    {
        mlx->center_y += 0.1 / mlx->zoom_level; // Move down
            choice(mlx->fract, mlx);
    }
    else if (keycode == 97) // 97 is the ASCII value for 'a'
    {
        mlx->center_x -= 0.1 / mlx->zoom_level; // Move left
            choice(mlx->fract, mlx);
    }
    else if (keycode == 100) // 100 is the ASCII value for 'd'
    {
        mlx->center_x += 0.1 / mlx->zoom_level; // Move right
            choice(mlx->fract, mlx);
    }
    else if (keycode == 32) // 32 is the ASCII value for 'space'
    {
        mlx->color_shift = (mlx->color_shift + 1) % 3; // Cycle through 3 different color schemes
        choice(mlx->fract, mlx);
    }
    else if (keycode == 65307)
        clean(mlx);

    return (0);
}


