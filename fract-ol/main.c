/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:02:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/04/24 21:28:19 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_window(char *title)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
    mlx->zoom_level = 1.0;
    mlx->center_x = 0.0; // Initialize center x
    mlx->center_y = 0.0;
	return (mlx);
}

int	main(int argc, char **argv)
{

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <1 for Mandelbrot, 2 for Julia>\n", argv[0]);
        return 1;
    }

    t_data *mlx = init_window("Fractal Viewer");
    if (!mlx)
    {
        fprintf(stderr, "Failed to initialize window\n");
        return 1;
    }
        mlx_mouse_hook(mlx->win, handle_scroll, mlx);

    int choice = atoi(argv[1]);
    if (choice == 1) {
        draw_mandelbrot(mlx);
    } else if (choice == 2) {
        t_data c = {.real = -0.8, .imag = 0.156}; // Example constant for Julia set
        draw_julia(mlx, c);
    } else {
        fprintf(stderr, "Invalid choice. Choose 1 for Mandelbrot, 2 for Julia\n");
        return 1;
    }

    mlx_loop(mlx->mlx);

    return 0;
}