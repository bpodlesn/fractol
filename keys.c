/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:52:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/27 15:36:53 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 1;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 15)
	{
		mlx->color = 0xaaaaaa;
		drawer(*mlx);
	}
}

void		keys2(int key, t_mlx *mlx)
{
	if (key == 21 && mlx->nu_fract != 4)
	{
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 4;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 23 && mlx->nu_fract != 5)
	{
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 5;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 22 && mlx->nu_fract != 6)
	{
		mlx->mover = 0.1;
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 6;
		mlx->counter = 0;
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
	if (key == 48)
	{
		mlx->color += 100000;
		drawer(*mlx);
	}
	if (key == 19 && mlx->nu_fract != 2)
	{
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 2;
		mlx->counter = 0;
		drawer(*mlx);
	}
}

void		keys4(int key, t_mlx *mlx)
{
	if (key == 20 && mlx->nu_fract != 3)
	{
		mlx->depth = 50;
		mlx->nu_fract = 3;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 26 && mlx->nu_fract != 7)
	{
		mlx->mover = 0.1;
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 7;
		mlx->counter = 0;
		drawer(*mlx);
	}
	if (key == 28 && mlx->nu_fract != 8)
	{
		mlx->mover = 0.1;
		mlx->mover = 0.1;
		mlx->depth = 50;
		mlx->nu_fract = 8;
		mlx->counter = 0;
		drawer(*mlx);
	}
}

void		keys5(int key, t_mlx *mlx)
{
	if (key == 4)
	{
		if (mlx->key_count == 0)
			mlx->key_count = 1;
		else
			mlx->key_count = 0;
		drawer(*mlx);
	}
	if (key == 124)
	{
		mlx->complex.max_true -= mlx->mover;
		mlx->complex.min_true -= mlx->mover;
		drawer(*mlx);
	}
	if (key == 126)
	{
		mlx->complex.max_false += mlx->mover;
		mlx->complex.min_false += mlx->mover;
		drawer(*mlx);
	}
}
