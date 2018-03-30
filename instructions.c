/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:36:06 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/27 16:57:22 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		else_instructions(t_mlx mlx, int c)
{
	mlx_string_put(mlx.init, mlx.window, 5,
	20, c, "Press <<TAB>> to change color");
	mlx_string_put(mlx.init, mlx.window, 5,
	40, c, "Press [ 1, 2, 3, 4, 5, 6, 7, 8 ] to change fractal");
	mlx_string_put(mlx.init, mlx.window, 5, 60, c, "1 - Mandelbrot");
	mlx_string_put(mlx.init, mlx.window, 5,
	80, c, "2 - Burnship");
	mlx_string_put(mlx.init, mlx.window, 5,
	100, c, "3 - 4thMandelbrot");
	mlx_string_put(mlx.init, mlx.window, 5,
	120, c, "4 - Quas Perpend");
	mlx_string_put(mlx.init, mlx.window, 5,
	140, c, "5 - Julia (can be modified by mouse move)");
	mlx_string_put(mlx.init, mlx.window, 5,
	160, c, "6 - Celtic Mandelbrot)");
	mlx_string_put(mlx.init, mlx.window, 5,
	180, c, "7 - Cubic Burnship");
	mlx_string_put(mlx.init, mlx.window, 5,
	200, c, "8 - Verticat Mandelbrot 5th");
	mlx_string_put(mlx.init, mlx.window, 5,
	220, c, "Press right/left/up/down to move");
	mlx_string_put(mlx.init, mlx.window, 5,
	240, c, "Use scroll to ZOOM");
	mlx_string_put(mlx.init, mlx.window, 5,
	260, c, "Use Z/C to change depth");
}

void		instructions(t_mlx mlx)
{
	int c;

	if (mlx.key_count == 0)
	{
		if (mlx.color == 0xaaaaaa)
			mlx_string_put(mlx.init, mlx.window,
			5, 20, 0xff, "Press <<H>> to see instructions");
		else
			mlx_string_put(mlx.init, mlx.window,
			5, 20, 0xffffff, "Press <<H>> to see instructions");
		mlx.key_count++;
	}
	else if (mlx.key_count == 1)
	{
		if (mlx.color == 0xaaaaaa)
			c = 0xff;
		else
			c = 0xffffff;
		else_instructions(mlx, c);
	}
}

void		usage(void)
{
	ft_putstr("\e[38;5;196mError: Invalid input!!!\e[0m\n");
	ft_putstr("\e[1;37mUsage - ./fractol fractal-name");
	ft_putstr("\e[1;37m[ m, b,");
	ft_putendl("\e[1;37m j, 4, c, q, cb, 5m ]");
	ft_putendl("\e[1;37mm: \e[38;5;203mMandelbrot\e[0m");
	ft_putendl("\e[1;37mb: \e[38;5;203mBurnship\e[0m");
	ft_putendl("\e[1;37mj: \e[38;5;203mJulia\e[0m");
	ft_putendl("\e[1;37m4: \e[38;5;203m4thMandelbrot\e[0m");
	ft_putendl("\e[1;37mc: \e[38;5;203mCeltic Mandelbrot\e[0m");
	ft_putendl("\e[1;37mq: \e[38;5;203mQuas Perpend\e[0m");
	ft_putendl("\e[1;37mcb: \e[38;5;203mCubic Burnship\e[0m");
	ft_putendl("\e[1;37m5m: \e[38;5;203mVertical Mandebrot 5th\e[0m");
	exit(0);
}
