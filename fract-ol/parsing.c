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

int	valid_fractal(char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		return (draw_mandelbrot);
	else if (!ft_strcmp(name, "julia"))
		return (draw_julia);
}