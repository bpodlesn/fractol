/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:28:56 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/24 17:53:30 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	launch_threads(pthread_t *tred, t_mlx *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	pthread_create(&tred[0], 0, ft_1, (void*)mlx);
	pthread_create(&tred[1], 0, ft_2, (void*)mlx);
	pthread_create(&tred[2], 0, ft_3, (void*)mlx);
	pthread_create(&tred[3], 0, ft_4, (void*)mlx);
	return (*mlx);
}

t_mlx	threads(t_mlx mlx)
{
	pthread_t	tred[4];

	mlx = launch_threads(tred, &mlx);
	pthread_join(tred[0], 0);
	pthread_join(tred[1], 0);
	pthread_join(tred[2], 0);
	pthread_join(tred[3], 0);
	return (mlx);
}

t_mlx	launch_threads2(pthread_t *tred2, t_mlx *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	pthread_create(&tred2[0], 0, fillpic1, (void*)mlx);
	pthread_create(&tred2[1], 0, fillpic2, (void*)mlx);
	pthread_create(&tred2[2], 0, fillpic3, (void*)mlx);
	pthread_create(&tred2[3], 0, fillpic4, (void*)mlx);
	return (*mlx);
}

t_mlx	threads_draw(t_mlx mlx)
{
	pthread_t	tred2[4];

	mlx = launch_threads2(tred2, &mlx);
	pthread_join(tred2[0], 0);
	pthread_join(tred2[1], 0);
	pthread_join(tred2[2], 0);
	pthread_join(tred2[3], 0);
	return (mlx);
}