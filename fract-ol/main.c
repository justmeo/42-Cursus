/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:02:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/01/13 16:43:41 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int stcmp(char *s1, char *s2)
// {
//     int i = 0;

//     while(s1[i] && s2[i] && s1[i] == s2[i])
//         i++;
//     if(i == ft_strlen(s2) && ft_strlen(s2) == ft_strlen(s1))
//         return (1);
//     else
//         return (0);
// }

// int main(int ac, char **av)
// {
//     char me[7] = "yassine";
//     int i = 0;
//     int j = 0;

//     if(stcmp(av[1],"yassine") == 1)
//         write(1,"d",1);
//     else
//         write(1,"a",1);
// }

typedef struct s_under
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
}			t_under;

int	main(void)
{
	t_data data;
	t_data img;int 



	data.mlx = mlx_init;
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "Yassine");
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,

			&img.endian);

	put_pixl(&img, 50, 50, 0x00FF0000); // put a red pixel at (50,50)
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 0, 0);
	mlx_loop(data.mlx);

}                                                                                             
