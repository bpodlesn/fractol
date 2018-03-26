/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pic_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:36:31 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:09:05 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*fillpic1(void *zlx)
{
	t_mlx	*mlx;
	int		i;
	int		retd;

	i = 0;
	mlx = (t_mlx*)zlx;
	while (i < 90000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i +
		1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*fillpic2(void *zlx)
{
	t_mlx	*mlx;
	int		i;
	int		retd;

	i = 89000;
	mlx = (t_mlx*)zlx;
	while (i < 180000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i +
		1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*fillpic3(void *zlx)
{
	t_mlx	*mlx;
	int		i;
	int		retd;

	i = 179000;
	mlx = (t_mlx*)zlx;
	while (i < 270000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i +
		1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void		*fillpic4(void *zlx)
{
	t_mlx	*mlx;
	int		i;
	int		retd;

	i = 269000;
	mlx = (t_mlx*)zlx;
	while (i < 360000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i +
		1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

t_mlx		launch_threads2(pthread_t *tred2, t_mlx *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	pthread_create(&tred2[0], 0, fillpic1, (void*)mlx);
	pthread_create(&tred2[1], 0, fillpic2, (void*)mlx);
	pthread_create(&tred2[2], 0, fillpic3, (void*)mlx);
	pthread_create(&tred2[3], 0, fillpic4, (void*)mlx);
	return (*mlx);
}
