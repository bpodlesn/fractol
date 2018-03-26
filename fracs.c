/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:20:27 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:06:18 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fractal_burnship(t_mlx mlx, int i)
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
		f_y = 2 * fabs(r_x * f_y) + mlx.types[i].complex_y;
		r_x = tmp + mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fractal_mandelbrot(t_mlx mlx, int i)
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
		r_x = tmp + mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fractal_mandelbrot_4th(t_mlx mlx, int i)
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
		f_y = 4 * r_x * f_y * (sqr_r_x - sqr_f_y) + mlx.types[i].complex_y;
		r_x = sqr_r_x * sqr_r_x + sqr_f_y * sqr_f_y - 6 * sqr_r_x * sqr_f_y
		+ mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

int			fract_img_quas_perpend(t_mlx mlx, int i)
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
		f_y = 4 * r_x * fabs(f_y) * fabs(sqr_r_x - sqr_f_y) +
		mlx.types[i].complex_y;
		r_x = sqr_r_x * sqr_r_x + sqr_f_y * sqr_f_y - 6
		* sqr_r_x * sqr_f_y + mlx.types[i].complex_x;
		if ((r_x * r_x + f_y * f_y) > 4)
			return (n);
		n++;
	}
	return (n);
}

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
