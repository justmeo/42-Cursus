

#include "fractol.h"

void clear_struct(t_data *mlx)
{
    mlx->mlx = NULL;
    mlx->win = NULL;
    mlx->img = NULL;
    mlx->addr = NULL;
    mlx->fract = 0;
    mlx->min_x = -2;
    mlx->max_x = 2;
    mlx->min_y = -2;
    mlx->max_y = 2;
    mlx->zoom_level = 1;
    mlx->center_x = 0;
    mlx->center_y = 0;
}