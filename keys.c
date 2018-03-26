/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:52:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 18:03:37 by bpodlesn         ###   ########.fr       */
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
	return (0);
}

void		keys(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if (key == 6)
	{
		mlx->depth += 1;
		drawer(*mlx);
	}
	if (key == 8)
	{
		mlx->depth > 0 ? mlx->depth -= 1 : 0;
		drawer(*mlx);
	}
	if (key == 18 && mlx->nu_fract != 1)
	{
		mlx->depth = 50;
		mlx->nu_fract = 1;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 19 && mlx->nu_fract != 2)
	{
		mlx->depth = 50;
		mlx->nu_fract = 2;
		mlx->counter = 0;
		drawer(*mlx);
	}
}

void		keys2(int key, t_mlx *mlx)
{
	if (key == 21 && mlx->nu_fract != 4)
	{
		mlx->depth = 50;
		mlx->nu_fract = 4;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 23 && mlx->nu_fract != 5)
	{
		mlx->depth = 50;
		mlx->nu_fract = 5;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 126)
	{
		mlx->complex.max_false += mlx->mover;
		mlx->complex.min_false += mlx->mover;
		drawer(*mlx);
	}
	if (key == 20 && mlx->nu_fract != 3)
	{
		mlx->depth = 50;
		mlx->nu_fract = 3;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 15)
	{
		mlx->color = 0xaaaaaa;
		drawer(*mlx);
	}
}

void		keys3(int key, t_mlx *mlx)
{
	if (key == 123)
	{
		mlx->complex.max_true += mlx->mover;
		mlx->complex.min_true += mlx->mover;
		drawer(*mlx);
	}
	if (key == 125)
	{
		mlx->complex.max_false -= mlx->mover;
		mlx->complex.min_false -= mlx->mover;
		drawer(*mlx);
	}
	if (key == 124)
	{
		mlx->complex.max_true -= mlx->mover;
		mlx->complex.min_true -= mlx->mover;
		drawer(*mlx);
	}
	if (key == 48)
	{
		mlx->color += 100000;
		drawer(*mlx);
	}
	if (key == 4)
	{
		if (mlx->key_count == 0)
			mlx->key_count = 1;
		else
			mlx->key_count = 0;
		drawer(*mlx);
	}
}

void		instructions(t_mlx mlx)
{
	if (mlx.key_count == 0)
	{
		mlx_string_put(mlx.init, mlx.window,
		5, 20, 0x51f6ff, "Press <<H>> to see instructions");
		mlx.key_count++;
	}
	else if (mlx.key_count == 1)
	{
		mlx_string_put(mlx.init, mlx.window, 5,
		20, 0x51f6ff, "Press <<TAB>> to change color");
		mlx_string_put(mlx.init, mlx.window, 5,
		40, 0x51f6ff, "Press [1, 2, 3, 4, 5] to change fractal");
		mlx_string_put(mlx.init, mlx.window, 5,
		60, 0x51f6ff, "1 - Mandelbrot");
		mlx_string_put(mlx.init, mlx.window, 5,
		80, 0x51f6ff, "2 - Burnship");
		mlx_string_put(mlx.init, mlx.window, 5,
		100, 0x51f6ff, "3 - 4thMandelbrot");
		mlx_string_put(mlx.init, mlx.window, 5,
		120, 0x51f6ff, "4 - Quas Perpend");
		mlx_string_put(mlx.init, mlx.window, 5,
		140, 0x51f6ff, "5 - Julia (can be modified by mouse move)");
		mlx_string_put(mlx.init, mlx.window, 5,
		160, 0x51f6ff, "Press right/left/up/down to move");
		mlx_string_put(mlx.init, mlx.window, 5,
		180, 0x51f6ff, "Use scroll to ZOOM");
	}
}
