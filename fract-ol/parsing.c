/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:32:32 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/05 03:45:32 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void parse_input(char *input, t_data *mlx)
{

    if (strcmp(input, "m") == 0 || strcmp(input, "M") == 0)
    {
        mlx->fract = 1; // Mandelbrot
    }
    else if (strcmp(input, "j") == 0 || strcmp(input, "J") == 0)
    {
        mlx->fract = 2; // Julia
    }
    else
    {
        print_fractal_options();
        exit(1);
    }

}
