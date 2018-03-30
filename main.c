/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:22:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/27 15:48:40 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_keys(int key, void *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	keys(key, mlx);
	keys2(key, mlx);
	keys3(key, mlx);
	keys4(key, mlx);
	keys5(key, mlx);
	return (0);
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
