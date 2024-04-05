/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:59:37 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/05 03:53:04 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fractol
# define fractol

# include "./Libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	real;
	double	imag;
}			t_data;

// void	draw_mandelbrot(t_data *mlx, int width, int height, int max_iter);
// void draw_julia(t_data *mlx, t_data c, int width, int height, int max_iter);

#endif