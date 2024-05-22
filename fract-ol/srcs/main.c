/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:02:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 04:14:45 by ymrabeti         ###   ########.fr       */
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
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, title);
	mlx->zoom_level = 2.5;
	mlx->center_x = 0.0;
	mlx->center_y = 0.0;
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_data	*mlx;

	mlx = init_window("Fractal Viewer");
	if (!mlx)
	{
		ft_putendl_fd("Failed to initialize window\n", 1);
		return (1);
	}
	mlx->color_shift = 0;
	parse_input(argv[1], mlx);
	arg(mlx, argv[2], argv[3], argc);
	mlx_mouse_hook(mlx->win, handle_scroll, mlx);
	choice(mlx->fract, mlx);
	print_controls();
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_loop(mlx->mlx);
	clean(mlx);
	return (0);
}
