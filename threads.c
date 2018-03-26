/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:28:56 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 17:16:29 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx			threads(t_mlx mlx)
{
	pthread_t	tred[4];

	mlx = launch_threads(tred, &mlx);
	pthread_join(tred[0], 0);
	pthread_join(tred[1], 0);
	pthread_join(tred[2], 0);
	pthread_join(tred[3], 0);
	return (mlx);
}

t_mlx			threads_draw(t_mlx mlx)
{
	pthread_t	tred2[4];

	mlx = launch_threads2(tred2, &mlx);
	pthread_join(tred2[0], 0);
	pthread_join(tred2[1], 0);
	pthread_join(tred2[2], 0);
	pthread_join(tred2[3], 0);
	return (mlx);
}

t_mlx			threads_complex(t_mlx mlx)
{
	pthread_t	tred3[4];

	mlx = launch_threads3(tred3, &mlx);
	pthread_join(tred3[0], 0);
	pthread_join(tred3[1], 0);
	pthread_join(tred3[2], 0);
	pthread_join(tred3[3], 0);
	return (mlx);
}

void			two_fract(char *argv_1, char *argv_2)
{
	char		*str;
	char		*tmp;

	tmp = ft_strnew(0);
	str = ft_strjoin(tmp, "./fractol ");
	free(tmp);
	tmp = ft_strjoin(str, argv_1);
	free(str);
	str = tmp;
	str = ft_strjoin(tmp, " & ./fractol ");
	free(tmp);
	tmp = str;
	str = ft_strjoin(tmp, argv_2);
	free(tmp);
	system(str);
	free(str);
}
