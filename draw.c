/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:33:07 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/26 18:02:05 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_retd(t_mlx mlx, int i)
{
	if (mlx.nu_fract == 1)
		return (fractal_mandelbrot(mlx, i));
	else if (mlx.nu_fract == 2)
		return (fractal_burnship(mlx, i));
	else if (mlx.nu_fract == 3)
		return (fractal_mandelbrot_4th(mlx, i));
	else if (mlx.nu_fract == 4)
		return (fract_img_quas_perpend(mlx, i));
	else if (mlx.nu_fract == 5)
		return (fractal_julia(mlx, i));
	return (0);
}

t_mlx	image(t_mlx mlx)
{
	mlx.image.bpp = 0;
	mlx.image.size_line = 0;
	mlx.image.endian = 0;
	mlx.image.img = mlx_new_image(mlx.init, 600, 600);
	mlx.image.line = mlx_get_data_addr(mlx.image.img,
	&(mlx.image.bpp), &(mlx.image.size_line), &(mlx.image.endian));
	return (mlx);
}

t_mlx	drawer(t_mlx mlx)
{
	int i;

	i = -1;
	mlx_clear_window(mlx.init, mlx.window);
	if (mlx.counter == 0)
		mlx = max_min_comp(mlx);
	mlx = threads_complex(mlx);
	mlx = threads_draw(mlx);
	mlx = threads(mlx);
	mlx_put_image_to_window(mlx.init, mlx.window, mlx.image.img, 0, 0);
	instructions(mlx);
	mlx_hook(mlx.window, 6, 0, ft_mouse, &mlx);
	mlx_hook(mlx.window, 2, 5, ft_keys, &mlx);
	mlx_mouse_hook(mlx.window, zoom, &mlx);
	mlx_loop(mlx.init);
	return (mlx);
}

t_mlx	start(t_mlx mlx, char *argv)
{
	mlx = make_coordinate(mlx);
	mlx = nu_fract(mlx, argv);
	mlx.counter = 0;
	mlx.color = 0xaaaaaa;
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WINX, WINY, "Fract0l");
	mlx = image(mlx);
	drawer(mlx);
	return (mlx);
}

t_mlx	nu_fract(t_mlx mlx, char *argv)
{
	ft_strcmp(argv, "m") == 0 ? mlx.nu_fract = 1 : 0;
	ft_strcmp(argv, "b") == 0 ? mlx.nu_fract = 2 : 0;
	ft_strcmp(argv, "4") == 0 ? mlx.nu_fract = 3 : 0;
	ft_strcmp(argv, "q") == 0 ? mlx.nu_fract = 4 : 0;
	ft_strcmp(argv, "j") == 0 ? mlx.nu_fract = 5 : 0;
	if (mlx.nu_fract == 0)
		usage();
	return (mlx);
}
