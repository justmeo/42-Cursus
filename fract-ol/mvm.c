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

int handle_scroll(int button, int x, int y, t_data *mlx)
{
    // Increase or decrease the zoom level based on the scroll direction
    if (button == 4) // Scroll up
        mlx->zoom_level *= 1.1;
    else if (button == 5) // Scroll down
        mlx->zoom_level /= 1.1;

    // Adjust the center of the view based on the mouse position
    mlx->center_x = (x - width / 2) / (0.5 * mlx->zoom_level * width) + mlx->center_x;
    mlx->center_y = (y - height / 2) / (0.5 * mlx->zoom_level * height) + mlx->center_y;

    // Redraw the Mandelbrot set with the new zoom level and center
    draw_mandelbrot(mlx);
    return (0);
}
