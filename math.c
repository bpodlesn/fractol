/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:13:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:14:20 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel_on(t_mlx mlx, int x, int y)
{
	int		i;

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
			x = (int)mlx.types[i].y * mlx.image.size_line +
			(int)mlx.types[i].x * 4;
			if (x < WINY * WINX * 4)
			{
				mlx.image.line[x] = mlx.types[i].blue;
				mlx.image.line[x + 1] = mlx.types[i].green;
				mlx.image.line[x + 2] = mlx.types[i].red;
			}
		}
	}
}

t_mlx		save_color(t_mlx mlx, int color, int i)
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

t_mlx		make_coordinate(t_mlx mlx)
{
	int		x;
	int		y;
	int		i;

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

t_mlx		max_min_comp(t_mlx mlx)
{
	mlx.complex.max_false = 1.25;
	mlx.complex.min_false = -1.25;
	mlx.complex.min_true = -2;
	if (mlx.nu_fract == 4 || mlx.nu_fract == 3)
	{
		mlx.complex.max_true = 1.14;
		mlx.complex.min_true = -1.36;
	}
	else if (mlx.nu_fract == 1)
		mlx.complex.max_true = 0.5;
	else if (mlx.nu_fract == 2)
	{
		mlx.complex.max_false = 2;
		mlx.complex.min_false = -2;
		mlx.complex.max_true = 1;
	}
	else if (mlx.nu_fract == 5)
	{
		mlx.complex.max_false = 1.75;
		mlx.complex.min_false = -1.75;
		mlx.complex.max_true = 1.75;
		mlx.complex.min_true = -1.75;
	}
	mlx.counter++;
	return (mlx);
}
