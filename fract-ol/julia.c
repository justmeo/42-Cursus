/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:35:28 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/05 03:35:37 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int julia(t_data z, t_data c, int max_iter) {
    int n;
    double real, imag;

    for (n = 0; n < max_iter; n++) {
        real = z.real * z.real - z.imag * z.imag + c.real;
        imag = 2 * z.real * z.imag + c.imag;
        z.real = real;
        z.imag = imag;
        if (z.real * z.real + z.imag * z.imag > 4) {
            return n;
        }
    }
    return max_iter;
}

void draw_julia(t_data *mlx, t_data c, int width, int height, int max_iter) {
    int color;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            // Map the pixel coordinates to a complex number
            t_data z = {
                .real = (double)x / width * 3.5 - 2.5,
                .imag = (double)y / height * 2.0 - 1.0
            };
            // Apply the julia function to the complex number
            color = julia(z, c, max_iter);
            // Draw the pixel
            mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
        }
    }
}