/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:59:37 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 05:07:40 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//  library

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//  Minilibx info

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 60

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		center_x;
	double		center_y;
	double		zoom_level;
	int			color_shift;
	int			fract;
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	t_complex	c;
	t_complex	z;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_mandelbrot(t_data *mlx);
void			draw_julia(t_data *mlx, t_complex c);
int				handle_scroll(int button, int x, int y, t_data *mlx);
int				key_press(int keycode, t_data *mlx);
void			clean(t_data *mlx);
void			choice(int x, t_data *mlx);
void			parse_input(char *input, t_data *mlx);
unsigned int	calculate_color(int m, t_data *mlx);
void			ft_putendl_fd(char *s, int fd);
void			print_fractal_options(void);
void			print_controls(void);
double			ft_atof(const char *str);
void			ft_putendl_fd(char *s, int fd);

void			arg(t_data *mlx, char *av2, char *av3, int ac);
void			draw_burningship(t_data *mlx);

#endif