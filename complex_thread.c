/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:31:01 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 12:54:43 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*rewrite_compl1(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = -1;
	while (++i < 90000)
		*mlx = coml_x_y(*mlx, i);
	pthread_exit(0);
}

void		*rewrite_compl2(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 89999;
	while (++i < 180000)
		*mlx = coml_x_y(*mlx, i);
	pthread_exit(0);
}

void		*rewrite_compl3(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 179999;
	while (++i < 270000)
		*mlx = coml_x_y(*mlx, i);
	pthread_exit(0);
}

void		*rewrite_compl4(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 269999;
	while (++i < 360000)
		*mlx = coml_x_y(*mlx, i);
	pthread_exit(0);
}

t_mlx		launch_threads3(pthread_t *tred3, t_mlx *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	pthread_create(&tred3[0], 0, rewrite_compl1, (void*)mlx);
	pthread_create(&tred3[1], 0, rewrite_compl2, (void*)mlx);
	pthread_create(&tred3[2], 0, rewrite_compl3, (void*)mlx);
	pthread_create(&tred3[3], 0, rewrite_compl4, (void*)mlx);
	return (*mlx);
}
