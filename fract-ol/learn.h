/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:55:50 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/04 15:33:33 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef learn
#define learn

#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
    void    *mlx;
    void    *win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

#endif


void draw_fractal(void (*fractal_func)(double, double, int, t_data *, int, int), t_data *img)
{
    for (int x = 0; x < img->width; x++)
    {
        for (int y = 0; y < img->height; y++)
        {
            double real = (x - img->width / 2.0) * 4.0 / img->width;
            double imag = (y - img->height / 2.0) * 4.0 / img->height;
            fractal_func(real, imag, 1000, img, x, y);
        }
    }
}


int get_color(int iter)
{
    int red = (iter % 256);
    int green = (iter * iter % 256);
    int blue = (iter * iter * iter % 256);
    return (red << 16 | green << 8 | blue);
}

void mandelbrot(double real, double imag, int max_iter, t_data *img, int x, int y)
{
    double r = 0.0, i = 0.0;
    int iter = 0;
    while (r*r + i*i <= 4.0 && iter < max_iter)
    {
        double temp = r*r - i*i + real;
        i = 2.0*r*i + imag;
        r = temp;
        iter++;
    }
    int color = get_color(iter);
    mlx_pixel_put(img->mlx, img->mlx_win, x, y, color);
}

void	values(t_data *img)
{
	img->width = 600;
	img->height = 600;
	img->base_color = 0x387575a3;
	img->flag = 0;
	img->zoom = 1;
	img->x_move = 0;
	img->y_move = 0;
	img->stop = 0;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->width, img->height, "fractol");
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int selection(char **av, t_data *data)
{
	if(ft_strncmp(av[1],"mandelbrot",10))
		data -> fract = 0;
	else if (ft_strncmp(av[1],"julia",5))
		data -> fract = 1;
	else if (ft_strncmp(av[1],"fern",4))
		data -> fract = 2;
	else
	{
		ft_putendl_fd("Usage: ./fractol [julia] or [mandelbrot] or [fern]");
			return(0);
	}
	return (1);
}

void zoom(int x, int y, double zoom_factor, t_data *img)
{
    img->x_center = (x - img->width / 2.0) * 4.0 / img->width;
    img->y_center = (y - img->height / 2.0) * 4.0 / img->height;
    img->scale *= zoom_factor;
    draw_fractal(img->fractal_func, img);
}

int handle_mouse(int button, int x, int y, t_data *img)
{
    if (button == 4) // Scroll up
        zoom(x, y, 1.25, img);
    else if (button == 5) // Scroll down
        zoom(x, y, 0.8, img);
    return (0);
}

void mandelbrot(double real, double imag, int max_iter, t_data *img, int x, int y)
{
    double r = 0.0, i = 0.0;
    int iter = 0;
    while (r*r + i*i <= 4.0 && iter < max_iter)
    {
        double temp = r*r - i*i + real;
        i = 2.0*r*i + imag;
        r = temp;
        iter++;
    }
    if (iter < max_iter)
    {
        double z = sqrt(r * r + i * i);
        double nu = log(log(z) / log(2)) / log(2);
        iter = iter + 1 - nu;
    }
    int color = get_color(iter);
    mlx_pixel_put(img->mlx, img->mlx_win, x, y, color);
}

int	main(int argc, char **argv)
{
    t_data img;
    values(&img);
    if (!selection(argv, &img))
        return (0);
    if (img.fract == 0)
        draw_fractal(mandelbrot, &img);
    else if (img.fract == 1)
        draw_fractal(julia, &img);
    else if (img.fract == 2)
        draw_fractal(fern, &img);
    mlx_mouse_hook(img.mlx_win, handle_mouse, &img);
    mlx_loop(img.mlx);
}