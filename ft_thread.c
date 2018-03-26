/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:35:47 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:07:42 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_1(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = -1;
	while (++i < 90000)
		create_lines(*mlx, i);
	pthread_exit(0);
}

void		*ft_2(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 89999;
	while (++i < 180000)
		create_lines(*mlx, i);
	pthread_exit(0);
}

void		*ft_3(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 179999;
	while (++i < 270000)
		create_lines(*mlx, i);
	pthread_exit(0);
}

void		*ft_4(void *zlx)
{
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx*)zlx;
	i = 269999;
	while (++i < 360000)
		create_lines(*mlx, i);
	pthread_exit(0);
}

t_mlx		launch_threads(pthread_t *tred, t_mlx *zlx)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)zlx;
	pthread_create(&tred[0], 0, ft_1, (void*)mlx);
	pthread_create(&tred[1], 0, ft_2, (void*)mlx);
	pthread_create(&tred[2], 0, ft_3, (void*)mlx);
	pthread_create(&tred[3], 0, ft_4, (void*)mlx);
	return (*mlx);
}
