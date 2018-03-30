/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracs_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:28:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/27 15:37:38 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fractal_julia(t_mlx mlx, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = mlx.types[i].complex_y;
	r_x = mlx.types[i].complex_x;
	while (n < mlx.depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * r_x * f_y + mlx.r_jul;
		r_x = tmp + mlx.f_jul;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fractal_celtic_mandelbrot(t_mlx mlx, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	tmp;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < mlx.depth)
	{
		tmp = (r_x * r_x) - (f_y * f_y);
		f_y = 2 * r_x * f_y + mlx.types[i].complex_y;
		r_x = fabs(tmp) + mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fractal_cubic_burnship(t_mlx mlx, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	sqr_r_x;
	double	sqr_f_y;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < mlx.depth)
	{
		sqr_r_x = r_x * r_x;
		sqr_f_y = f_y * f_y;
		f_y = ((sqr_r_x * 3.0) - sqr_f_y) * fabs(f_y) + mlx.types[i].complex_y;
		r_x = ((sqr_r_x - (sqr_f_y * 3.0)) * fabs(r_x) +
		mlx.types[i].complex_x);
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fractal_verticat_mandelbrot_5th(t_mlx mlx, int i)
{
	int		n;
	double	r_x;
	double	f_y;
	double	sqr_r_x;
	double	sqr_f_y;

	n = 0;
	f_y = 0;
	r_x = 0;
	while (n < mlx.depth)
	{
		sqr_r_x = r_x * r_x;
		sqr_f_y = f_y * f_y;
		f_y = -f_y * (5 * (sqr_r_x * sqr_r_x) - 10 * (sqr_r_x * sqr_f_y) +
		(sqr_f_y * sqr_f_y)) + mlx.types[i].complex_y;
		r_x = r_x * ((sqr_r_x * sqr_r_x) - 10 * (sqr_r_x * sqr_f_y) +
		(sqr_f_y * sqr_f_y) + 5 * (sqr_f_y * sqr_f_y)) +
		mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}
