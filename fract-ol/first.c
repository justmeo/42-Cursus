#include "learn.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



#define x 400

int deal_key(int key)
{
    // Handle key events, for example, zooming in or out
    if (key == 53) // 53 is the keycode for the Esc key, you can change it to the desired key
        exit(0);
    else if (key == 24) // 24 is the keycode for the '+' key
    {
        // Implement zoom in logic here
        // Adjust the scale factor or coordinates of your objects
    }
    else if (key == 27) // 27 is the keycode for the '-' key
    {
        // Implement zoom out logic here
        // Adjust the scale factor or coordinates of your objects
    }
    return (0);
}

int	main(void)
{
	t_data data;
	t_data img;
	int i = x;
	int j = x;


	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 2000, 1200, "Hello world!");
	img.img = mlx_new_image(data.mlx, 2000, 1200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	while(i <= (x * 2))
	{
		my_mlx_pixel_put(&img, i, x, 0x00FF0000);
		i++;
	}
	while(j <= (x * 2))
	{
		my_mlx_pixel_put(&img, x, j, 0x00FF0000);
		j++;
	}
	j = i = x;
	while(i <= (x * 2))
	{
		my_mlx_pixel_put(&img, i, j * 2, 0x00FF0000);
		i++;
	}
		while(j <= (x * 2))
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j++;
	}

	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.mlx);
}

// typedef struct {
//     void *mlx;
//     void *win;
// } t_data;

// // Function to handle key events
// int deal_key(int key) {
//     if (key == 53)  // 53 is the ASCII code for the 'Esc' key
//         exit(0);    // Exit the program when 'Esc' is pressed
//     return (0);
// }

// int main() {
//     t_data data;

//     // Initialize MiniLibX
//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, 800, 600, "Open and Exit");

//     // Set the hook function for key events
//     mlx_hook(data.win, 2, 1L << 0, deal_key, &data);

//     // Start the MiniLibX loop
//     mlx_loop(data.mlx);

//     return 0;
// }


