/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:12:36 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/01/13 18:02:18 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

typedef struct  s_img
{
    void        *img_ptr;
    int         *data;
    int         size_l;
    int         bpp;
    int         endian;
}               t_img;

void    put_pixel(t_img *img, int x, int y, int color)
{
    if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
        img->data[y * WIDTH + x] = color;
}

void    draw_mandelbrot(void *mlx, void *win)
{
    t_img   img;

    img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double a = 0, b = 0, c, d, n = 0;
            while (n < MAX_ITER)
            {
                c = a;
                d = b;
                a = a*a - b*b + (x - WIDTH / 2.0) * 4.0 / WIDTH;
                b = 2*c*d + (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
                if (a*a + b*b > 4)
                    break;
                    
                n++;
            }
            int color = (n < MAX_ITER) ? ((int)n*255) : 0;
            put_pixel(&img, x, y, color);
        }
    }
    mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
    mlx_destroy_image(mlx, img.img_ptr);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
    draw_mandelbrot(mlx, win);
    mlx_loop(mlx);
    return (0);
}