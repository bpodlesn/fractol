/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:22:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:16:08 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		usage(void)
{
	ft_putstr("\e[38;5;196mError: Invalid input!!!\e[0m\n");
	ft_putstr("Usage - ./fractol fractal-name");
	ft_putstr("[\e[38;5;35mm\e[0m, \e[38;5;197mb\e[0m, ");
	ft_putendl("\e[38;5;123mj\e[0m, \e[38;5;112m4\e[0m, \e[38;5;90mq\e[0m]");
	ft_putendl("\e[38;5;35mm - Mandelbrot");
	ft_putendl("\e[38;5;197mb - Burnship");
	ft_putendl("\e[38;5;123mj - Julia");
	ft_putendl("\e[38;5;112m4 - 4thMandelbrot");
	ft_putendl("\e[38;5;90mq - Quas Perpend\e[0m");
	exit(0);
}

int			ft_mouse(int x, int y, t_mlx *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	if (mlx->nu_fract == 5)
	{
		*mlx = real_julia(*mlx, x);
		*mlx = false_julia(*mlx, y);
		*mlx = drawer(*mlx);
	}
	return (0);
}

t_mlx		false_julia(t_mlx mlx, int y)
{
	double	range_y;

	range_y = (mlx.complex.max_false - mlx.complex.min_false) / WINY;
	mlx.f_jul = y * range_y + mlx.complex.min_false;
	return (mlx);
}

t_mlx		real_julia(t_mlx mlx, int x)
{
	double	range_x;

	range_x = (mlx.complex.max_true - mlx.complex.min_true) / WINX;
	mlx.r_jul = x * range_x + mlx.complex.min_true;
	return (mlx);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.nu_fract = 0;
	mlx.depth = 50;
	mlx.mover = 0.1;
	if (argc != 2 && argc != 3)
		usage();
	else if (argc == 2)
		start(mlx, argv[1]);
	else if (argc == 3)
		two_fract(argv[1], argv[2]);
	return (0);
}
