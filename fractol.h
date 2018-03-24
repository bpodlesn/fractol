/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:22:31 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/24 17:46:25 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <pthread.h>
# include <fcntl.h>
# include <mlx.h>

# define WINX 600
# define WINY 600
# define PIXELS 360000

typedef	struct	s_complex
{
	double		max_true;
	double		min_true;
	double		max_false;
	double		min_false;
}				t_complex;

typedef	struct		s_types
{
	double			x;
	double			y;
	double			complex_x;
	double			complex_y;
	int				red;
	int				green;
	int				blue;
}					t_types;

typedef	struct		s_image
{
	void 			*img;
	char			*line;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*init;
	void			*window;
	int				color;
	int				depth;
	t_image			image;
	t_types			*types;
	t_complex		complex;
	double			comp_mouse_x;
	double			comp_mouse_y;
	double			r_jul;
	double			f_jul;
	int				nu_fract;
	int				counter;
}					t_mlx;

int 	choose_retd(t_mlx mlx, int i);
int		fractal_mandelbrot(t_mlx mlx, int i);
int		fractal_burnship(t_mlx mlx, int i);
int		fractal_mandelbrot_4th(t_mlx mlx, int i);
int		fract_img_quas_perpend(t_mlx mlx, int i);
void	put_pixel_on(t_mlx mlx, int x, int y);
void	create_lines(t_mlx mlx, int i);
t_mlx	save_color(t_mlx mlx, int color, int i);
t_mlx	fillpic(t_mlx mlx, int i, int retd);
t_mlx	make_coordinate(t_mlx mlx);
t_mlx	image(t_mlx mlx);
t_mlx	coml_x_y(t_mlx mlx, int i);
t_mlx	start(t_mlx mlx, char *argv);
t_mlx	drawer(t_mlx mlx);
t_mlx	nu_fract(t_mlx, char *argv);
t_mlx	rewrite_compl(t_mlx mlx);
t_mlx	max_min_comp(t_mlx mlx);
t_mlx	real_julia(t_mlx mlx, int x);
t_mlx	false_julia(t_mlx mlx, int y);
t_mlx	coml_x_y(t_mlx mlx, int i);
t_mlx	comp_my(t_mlx mlx, int y);
t_mlx	comp_mx(t_mlx mlx, int x);
t_mlx	mouse_zoom(t_mlx mlx, int x, int y, int key);
t_mlx	launch_threads(pthread_t *tred, t_mlx *mlx);
t_mlx	threads(t_mlx mlx);
void	*ft_1(void *mlx);
void	*ft_2(void *mlx);
void	*ft_3(void *mlx);
void	*ft_4(void *mlx);
void	*fillpic1(void *zlx);
void	*fillpic2(void *zlx);
void	*fillpic3(void *zlx);
void	*fillpic4(void *zlx);
int		zoom(int key, int x, int y, t_mlx *zlx);
int		fractal_julia(t_mlx mlx, int i);
// void	frac_part(t_mlx mlx, int i, int retd);
int 	ft_mouse(int x, int y, t_mlx *zlx);
int		ft_keys(int key, void *zlx);
t_mlx	launch_threads2(pthread_t *tred, t_mlx *zlx);
t_mlx	threads_draw(t_mlx mlx);

#endif
