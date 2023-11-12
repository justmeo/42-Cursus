#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>


// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// #define x 400

// int	main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data img;
// 	int i = x;
// 	int j = x;


// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 2000, 1200, "Hello world!");
// 	img.img = mlx_new_image(mlx, 2000, 1200);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);

// 	while(i <= (x * 2))
// 	{
// 		my_mlx_pixel_put(&img, i, x, 0x00FF0000);
// 		i++;
// 	}
// 	while(j <= (x * 2))
// 	{
// 		my_mlx_pixel_put(&img, x, j, 0x00FF0000);
// 		j++;
// 	}
// 	j = i = x;
// 	while(i <= (x * 2))
// 	{
// 		my_mlx_pixel_put(&img, i, j * 2, 0x00FF0000);
// 		i++;
// 	}
// 		while(j <= (x * 2))
// 	{
// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 		j++;
// 	}

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

#define WIDTH 800
#define HEIGHT 600

double my_function(double x) {
    // Define your function here
    return sin(x); // Example: sine function
}

void draw_function(void *mlx_ptr, void *win_ptr) {
    double scale_x = 0.1; // Adjust the scale as needed
    double scale_y = 100.0; // Adjust the scale as needed

    for (int i = 0; i < WIDTH; i++) {
        double x = (i - WIDTH / 2) * scale_x;
        double y = my_function(x) * scale_y;

        mlx_pixel_put(mlx_ptr, win_ptr, i, HEIGHT / 2 - y, 0xFFFFFF); // White pixel
    }
}

void draw_circle(void *mlx_ptr, void *win_ptr, int center_x, int center_y, int radius) {
    for (int angle = 0; angle <= 360; angle++) {
        double radian_angle = angle * M_PI / 180.0;
        int x = center_x + radius * cos(radian_angle);
        int y = center_y + radius * sin(radian_angle);

        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF0000); // Red pixel for the circle
    }
}

int main() {
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Function Plot");

    draw_function(mlx_ptr, win_ptr);

    int circle_center_x = WIDTH / 4;
    int circle_center_y = HEIGHT / 4;
    int circle_radius = 50;

    draw_circle(mlx_ptr, win_ptr, circle_center_x, circle_center_y, circle_radius);

    mlx_loop(mlx_ptr);

    return 0;
}