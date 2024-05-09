

#include "fractol.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		write(fd, &*s++, 1);
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	while (*s)
		write(fd, &*s++, 1);
}

void	print_fractal_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("\tT - Tricorn", 1);
	ft_putendl_fd("\tX - Mandelbox", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m",
			1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =========================+",
			1);
	ft_putendl_fd("WASD or arrow keys\tmove view.", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Spacebar\t\tchange color schemes.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
	ft_putendl_fd("+====================================================+\n",
			1);
}