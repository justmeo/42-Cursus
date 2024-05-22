/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:32:32 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/05/10 05:03:00 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	parse_input(char *input, t_data *mlx)
{
	if (input == NULL)
	{
		print_fractal_options();
		exit(1);
	}
	if (ft_strcmp(input, "m") == 0 || ft_strcmp(input, "M") == 0)
	{
		mlx->fract = 1;
	}
	else if (ft_strcmp(input, "j") == 0 || ft_strcmp(input, "J") == 0)
	{
		mlx->fract = 2;
	}
	else if (ft_strcmp(input, "b") == 0 || ft_strcmp(input, "B") == 0)
	{
		mlx->fract = 3;
	}
	else
	{
		print_fractal_options();
		exit(1);
	}
}

void	error_msg(t_data *mlx)
{
	print_fractal_options();
	clean(mlx);
}

void	arg(t_data *mlx, char *av2, char *av3, int ac)
{
	if (ac != 2 && mlx->fract != 2)
		error_msg(mlx);
	else if (ac == 2)
	{
		mlx->c.real = -0.8;
		mlx->c.imag = 0.156;
	}
	else if (ac == 4)
	{
		if ((ft_atof(av2) >= -2 && ft_atof(av2) <= 2) && (ft_atof(av3) >= -2
				&& ft_atof(av3) <= 2))
		{
			mlx->c.real = ft_atof(av2);
			mlx->c.imag = ft_atof(av3);
		}
		else
			error_msg(mlx);
	}
	else
		error_msg(mlx);
}
