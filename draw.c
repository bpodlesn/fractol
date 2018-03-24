/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:33:07 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/24 17:58:01 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	frac_part(t_mlx mlx, int i, int retd)
// {
// 	if (mlx.nu_fract == 4)
// 		while(i < 360000)
// 		{
// 			retd = fract_img_quas_perpend(mlx, i);
// 			retd < mlx.depth ? save_color(mlx, (((retd + 1) % (i + 1)) * mlx.color), i) : save_color(mlx, 0, i);
// 			i++;
// 		}
// 	else if (mlx.nu_fract == 5)
// 		while(i < 360000)
// 		{
// 			retd = fractal_julia(mlx, i);
// 			retd < mlx.depth ? save_color(mlx, (((retd + 1) % (i + 1)) * mlx.color), i) : save_color(mlx, 0, i);
// 			i++;
// 		}
// }

void	*fillpic1(void *zlx)
{
	t_mlx *mlx;
	int i;
	int retd;

	i = 0;
	mlx = (t_mlx*)zlx;
	while(i < 90000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i + 1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*fillpic2(void *zlx)
{
	t_mlx *mlx;
	int i;
	int retd;

	i = 89000;
	mlx = (t_mlx*)zlx;
	while(i < 180000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i + 1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*fillpic3(void *zlx)
{
	t_mlx *mlx;
	int i;
	int retd;

	i = 179000;
	mlx = (t_mlx*)zlx;
	while(i < 270000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i + 1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

void	*fillpic4(void *zlx)
{
	t_mlx *mlx;
	int i;
	int retd;

	i = 269000;
	mlx = (t_mlx*)zlx;
	while(i < 360000)
	{
		retd = choose_retd(*mlx, i);
		retd < mlx->depth ? save_color(*mlx, (((retd + 1) % (i + 1)) * mlx->color), i) : save_color(*mlx, 0, i);
		i++;
	}
	pthread_exit(0);
}

int 	choose_retd(t_mlx mlx, int i)
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

t_mlx	rewrite_compl(t_mlx mlx)
{
	int i;

	i = -1;
	while (++i < 360000)
		mlx = coml_x_y(mlx, i);
	return (mlx);
}

void	*ft_1(void *zlx)
{
	t_mlx *mlx;
	int i;
	
	mlx = (t_mlx*)zlx;
	i = -1;
	while (++i < 90000)
	{
		create_lines(*mlx, i);
	}
	// return (mlx);
	pthread_exit(0);
}

void	*ft_2(void *zlx)
{
	t_mlx *mlx;
	int i;
	
	mlx = (t_mlx*)zlx;
	i = 89999;
	while (++i < 180000)
	{
		create_lines(*mlx, i);
	}
	// return (mlx);
	pthread_exit(0);
}

void	*ft_3(void *zlx)
{
	t_mlx *mlx;
	int i;

	mlx = (t_mlx*)zlx;
	i = 179999;
	while (++i < 270000)
	{
		create_lines(*mlx, i);
	}
	pthread_exit(0);
	// return (mlx);
}

void	*ft_4(void *zlx)
{
	t_mlx *mlx;
	int i;
	
	mlx = (t_mlx*)zlx;
	i = 269999;
	while (++i < 360000)
	{
		create_lines(*mlx, i);
	}
	pthread_exit(0);
	// return (mlx);
}

t_mlx	drawer(t_mlx mlx)
{
	int i;

	i = -1;
	mlx_clear_window(mlx.init, mlx.window);
	if (mlx.counter == 0)
		mlx = max_min_comp(mlx);
	mlx = rewrite_compl(mlx);
	// mlx = fillpic(mlx, 0, 0	);
	mlx = threads_draw(mlx);
	mlx = threads(mlx);
	// while (++i < 360000)
	// {
	// 	// mlx = coml_x_y(mlx, i);
	// 	mlx = create_lines(mlx, i);
	// }
	mlx_put_image_to_window(mlx.init, mlx.window, mlx.image.img, 0, 0);
	mlx_hook(mlx.window, 6, 0, ft_mouse, &mlx);
	mlx_hook(mlx.window, 2, 5, ft_keys, &mlx);
	mlx_mouse_hook(mlx.window, zoom, &mlx);
	mlx_loop(mlx.init);
	return (mlx);
}
