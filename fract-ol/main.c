/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:02:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/05 03:55:28 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_window(int width, int height, char *title)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
	return (mlx);
}

int	mandelbrot(t_data c, int max_iter)
{
	t_data	z;
	int		n;
	double	real;
	double	imag;

	z.real = 0;
	z.imag = 0;
	for (n = 0; n < max_iter; n++)
	{
		real = z.real * z.real - z.imag * z.imag + c.real;
		imag = 2 * z.real * z.imag + c.imag;
		z.real = real;
		z.imag = imag;
		if (z.real * z.real + z.imag * z.imag > 4)
		{
			return (n);
		}
	}
	return (max_iter);
}

void	draw_mandelbrot(t_data *mlx, int width, int height, int max_iter)
{
	int	color;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			// Map the pixel coordinates to a complex number
			t_data c = {
				.real = (double)x / width * 3.5 - 2.5,
				.imag = (double)y / height * 2.0 - 1.0};
			// Apply the mandelbrot function to the complex number
			color = mandelbrot(c, max_iter);
			// Draw the pixel
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		}
	}
}

int	julia(t_data z, t_data c, int max_iter)
{
	int	n;

	double real, imag;
	for (n = 0; n < max_iter; n++)
	{
		real = z.real * z.real - z.imag * z.imag + c.real;
		imag = 2 * z.real * z.imag + c.imag;
		z.real = real;
		z.imag = imag;
		if (z.real * z.real + z.imag * z.imag > 4)
		{
			return (n);
		}
	}
	return (max_iter);
}

void	draw_julia(t_data *mlx, t_data c, int width, int height, int max_iter)
{
	int	color;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			// Map the pixel coordinates to a complex number
			t_data z = {
				.real = (double)x / width * 3.5 - 2.5,
				.imag = (double)y / height * 2.0 - 1.0};
			// Apply the julia function to the complex number
			color = julia(z, c, max_iter);
			// Draw the pixel
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, color);
		}
	}
}

int	main(int argc, char **argv)
{
    int width = 800;
    int height = 600;
    int max_iter = 1000;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <1 for Mandelbrot, 2 for Julia>\n", argv[0]);
        return 1;
    }

    t_data *mlx = init_window(width, height, "Fractal Viewer");
    if (!mlx)
    {
        fprintf(stderr, "Failed to initialize window\n");
        return 1;
    }

    int choice = atoi(argv[1]);
    if (choice == 1) {
        draw_mandelbrot(mlx, width, height, max_iter);
    } else if (choice == 2) {
        t_data c = {.real = -0.8, .imag = 0.156}; // Example constant for Julia set
        draw_julia(mlx, c, width, height, max_iter);
    } else {
        fprintf(stderr, "Invalid choice. Choose 1 for Mandelbrot, 2 for Julia\n");
        return 1;
    }

    mlx_loop(mlx->mlx);

    return 0;
}