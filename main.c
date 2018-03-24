/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:22:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/24 17:39:07 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_keys(int key, void *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	if (key == 53)
		exit(0);
	if (key == 6)
	{
	 	mlx->depth+= 1;
	 	drawer(*mlx);
	}
	if (key == 8)
	{
		mlx->depth > 0 ? mlx->depth -= 1 : 0;
	 	drawer(*mlx);
	}
	if (key == 48)
	{
		mlx->color += 100000;
		drawer(*mlx);
	}
	if (key == 18 && mlx->nu_fract != 1)
	{
		mlx->nu_fract = 1;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 19)
	{
		mlx->nu_fract = 2;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 20)
	{
		mlx->nu_fract = 3;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 21)
	{
		mlx->nu_fract = 4;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 23)
	{
		mlx->nu_fract = 5;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 126)
	{
		mlx->complex.max_false += 0.01;
		mlx->complex.min_false += 0.01;
		drawer(*mlx);
	}
	if (key == 123)
	{
		mlx->complex.max_true += 0.01;
		mlx->complex.min_true += 0.01;
		drawer(*mlx);
	}
	if (key == 125)
	{
		mlx->complex.max_false -= 0.01;
		mlx->complex.min_false -= 0.01;
		drawer(*mlx);
	}
	if (key == 124)
	{
		mlx->complex.max_true -= 0.01;
		mlx->complex.min_true -= 0.01;
		drawer(*mlx);
	}
	return (0);
}

void	usage()
{
	ft_putstr("Error: Invalid input!!!\n");
	ft_putendl("Usage - ./fractol fractal-name [m, b]");
	exit(0);
}

void	put_pixel_on(t_mlx mlx, int x, int y)
{
	int i;

	i = (x * 4) + (y * mlx.image.size_line);
	mlx.image.line[i++] = 255;
	mlx.image.line[i++] = 255;
	mlx.image.line[i] = 0;
}

void		create_lines(t_mlx mlx, int i)
{
	int		x;

	if ((int)mlx.types[i].y >= 0 && (int)mlx.types[i].x >= 0)
	{
		if ((int)mlx.types[i].y < WINY && (int)mlx.types[i].x < WINX)
		{
			x = (int)mlx.types[i].y * mlx.image.size_line + (int)mlx.types[i].x * 4;
			if (x < WINY * WINX * 4)
			{
				mlx.image.line[x] = mlx.types[i].blue;
				mlx.image.line[x + 1] = mlx.types[i].green;
				mlx.image.line[x + 2] = mlx.types[i].red;
			}
		}
	}
	// return (mlx);
}

t_mlx	save_color(t_mlx mlx, int color, int i)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16);
	green = (color >> 8) - (red << 8);
	blue = (color) - (red << 16) - (green << 8);
	mlx.types[i].red = red;
	mlx.types[i].green = green;
	mlx.types[i].blue = blue;
	return (mlx);
}

t_mlx	make_coordinate(t_mlx mlx)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	mlx.types = malloc(sizeof(t_types) * PIXELS);
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			mlx.types[i].y = y;
			mlx.types[i].x = x;
			i++;
			x++;
		}
		y++;
	}
	return (mlx);
}

int 	ft_mouse(int x, int y, t_mlx *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	if (mlx->nu_fract == 5)
	{
		*mlx = real_julia(*mlx, x);
		*mlx = false_julia(*mlx, y);
		*mlx = drawer(*mlx);
	}
	return (0);
}

t_mlx	nu_fract(t_mlx mlx, char *argv)
{
	ft_strcmp(argv, "m") == 0 ? mlx.nu_fract = 1 : 0;
	ft_strcmp(argv, "b") == 0 ? mlx.nu_fract = 2 : 0;
	ft_strcmp(argv, "4") == 0 ? mlx.nu_fract = 3 : 0;
	ft_strcmp(argv, "q") == 0 ? mlx.nu_fract = 4 : 0;
	ft_strcmp(argv, "j") == 0 ? mlx.nu_fract = 5 : 0;
	return (mlx);
}

t_mlx	max_min_comp(t_mlx mlx)
{
	if (mlx.nu_fract == 4 || mlx.nu_fract == 3)
	{
		mlx.complex.max_false = 1.25;
		mlx.complex.min_false = -1.25;
		mlx.complex.max_true = 1.14;
		mlx.complex.min_true = -1.36;
		mlx.counter++;
	}
	else if (mlx.nu_fract == 1)
	{
		mlx.complex.max_false = 1.25;
		mlx.complex.min_false = -1.25;
		mlx.complex.max_true = 0.5;
		mlx.complex.min_true = -2;
		mlx.counter++;
	}
	else if (mlx.nu_fract == 2)
	{
		mlx.complex.max_false = 2;
		mlx.complex.min_false = -2;
		mlx.complex.max_true = 1;
		mlx.complex.min_true = -2;
		mlx.counter++;
	}
	else if (mlx.nu_fract == 5)
	{
		mlx.complex.max_false = 1.75;
		mlx.complex.min_false = -1.75;
		mlx.complex.max_true = 1.75;
		mlx.complex.min_true = -1.75;
		mlx.counter++;
	}
	return (mlx);
}

t_mlx	false_julia(t_mlx mlx, int y)
{
	double	range_y;

	range_y = (mlx.complex.max_false - mlx.complex.min_false) / WINY;
	mlx.f_jul = y * range_y + mlx.complex.min_false;
	return (mlx);
}

t_mlx	real_julia(t_mlx mlx, int x)
{
	double	range_x;

	range_x = (mlx.complex.max_true - mlx.complex.min_true) / WINX;
	mlx.r_jul = x * range_x + mlx.complex.min_true;
	return (mlx);
}

t_mlx	start(t_mlx mlx, char *argv)
{
	mlx = make_coordinate(mlx);
	mlx = nu_fract(mlx, argv);
	mlx.counter = 0;
	mlx.color = 0xfff0a0;
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WINX, WINY, "Fract0l");
	mlx = image(mlx);
	drawer(mlx);
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	mlx.nu_fract = 0;
	mlx.depth = 50;
	if (argc != 2)
		usage();
	else if (argc == 2)
		start(mlx, argv[1]);
	printf("%s\n", argv[1]);
	return (0);
}
