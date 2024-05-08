/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:59:37 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/25 00:23:05 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fractol
# define fractol

//  library

# include "./Libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//  Minilibx info
 
#define width 1440
#define height 1080
#define max_iter 60

//   Keycodes for mlx
 
# define A					0
# define S					1
# define D					2
# define W					13
# define ESC				53
# define PG_UP				116
# define PG_DOWN			121
# define SCROLL_UP			4
# define LEFT_CLICK			1
# define SCROLL_DOWN		5

typedef struct  s_complex {
    double real;
    double imag;
}               t_complex;

typedef struct  s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  center_x;
    double  center_y;
    double  zoom_level;
    int color_shift;
	int fract;
	int min_x;
	int max_x;
	int min_y;
	int max_y;
}               t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_mandelbrot(t_data *mlx);
double map(int value, int start1, int stop1, double start2, double stop2);
void draw_julia(t_data *mlx, t_complex c);
int handle_scroll(int button, int x, int y, t_data *mlx);
int key_press(int keycode, t_data *mlx);
void clean(t_data *mlx);
void choice (int x, t_data *mlx);
void parse_input(char *input,t_data *mlx);





#endif