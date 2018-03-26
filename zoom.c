/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:20:03 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:05:04 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_mlx		coml_x_y(t_mlx mlx, int i)
{
	double	range_x;
	double	range_y;

	range_x = 0;
	range_y = 0;
	range_y = (mlx.complex.max_false - mlx.complex.min_false) / WINY;
	mlx.types[i].complex_y = mlx.types[i].y * range_y + mlx.complex.min_false;
	range_x = (mlx.complex.max_true - mlx.complex.min_true) / WINX;
	mlx.types[i].complex_x = mlx.types[i].x * range_x + mlx.complex.min_true;
	return (mlx);
}

t_mlx		comp_my(t_mlx mlx, int y)
{
	double	range_y;

	range_y = 0;
	range_y = (mlx.complex.max_false - mlx.complex.min_false) / WINY;
	mlx.comp_mouse_y = y * range_y + mlx.complex.min_false;
	return (mlx);
}

t_mlx		comp_mx(t_mlx mlx, int x)
{
	double	range_x;

	range_x = 0;
	range_x = (mlx.complex.max_true - mlx.complex.min_true) / WINX;
	mlx.comp_mouse_x = x * range_x + mlx.complex.min_true;
	return (mlx);
}

t_mlx		mouse_zoom(t_mlx mlx, int x, int y, int key)
{
	int		i;
	double	c;

	i = 0;
	mlx = comp_mx(mlx, x);
	mlx = comp_my(mlx, y);
	if (key == 5)
	{
		mlx.mover *= 0.9;
		c = 0.9;
	}
	else
	{
		mlx.mover /= 0.9;
		c = 1.1;
	}
	MAX_TRUE = MAX_TRUE * c + mlx.comp_mouse_x * (1 - c);
	MIN_TRUE = MIN_TRUE * c + mlx.comp_mouse_x * (1 - c);
	MAX_FALSE = MAX_FALSE * c + mlx.comp_mouse_y * (1 - c);
	MIN_FALSE = MIN_FALSE * c + mlx.comp_mouse_y * (1 - c);
	mlx = drawer(mlx);
	return (mlx);
}

int			zoom(int key, int x, int y, t_mlx *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	if (key == 4 || key == 5)
		*mlx = mouse_zoom(*mlx, x, y, key);
	return (0);
}
