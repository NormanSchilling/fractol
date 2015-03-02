/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:01:40 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 15:37:12 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <mlx.h>
# include <math.h>
# include </usr/X11/include/X11/X.h>
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 700
# define DEPTH_MANDELBROT 30
# define DEPTH_JULIA 30
# define DEPTH_NEWTON 30
# define DEPTH_BURNINGSHIP 30

typedef struct		s_fractal
{
	int				x;
	int				y;
	int				a;
	float			rc;
	float			ic;
	float			rz;
	float			iz;
	float			r;
	float			i;
	float			min_x;
	float			min_y;
	float			max_x;
	float			max_y;
}					t_fractal;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_image
{
	void			*image;
	char			*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_mouse
{
	float			x;
	float			y;
}					t_mouse;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*fractol;
	float			zoom;
	t_fractal		m;
	t_fractal		j;
	t_fractal		b;
	t_image			i;
	t_mouse			mouse;
	t_color			color;
}					t_env;

/*
** init.c
*/
void				ft_put_pixel_to_image(t_image *i, int x,
					int y, t_color color);
double				get_time(void);
int					main_loop(t_env *e);
void				ft_init(char *fractol);

/*
** hook.c
*/
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int mousecode, int x, int y, t_env *e);
int					mouse_hook_position(int x, int y, t_env *e);
int					expose_hook(t_env *e);

/*
** display.c
*/
void				ft_zoom(t_env *e);
void				ft_dezoom(t_env *e);
void				ft_display(t_env *e);

/*
** mandelbrot.c
*/
void				mandelbrot_choose_color(t_fractal *m, t_color *color);
void				mandelbrot_depth_loop(t_env *e, t_fractal *m);
void				mandelbrot_horizontal_loop(t_env *e, t_fractal *m);
void				mandelbrot_vertical_loop(t_env *e, t_fractal *m);
t_fractal			init_mandelbrot(t_env *e);

/*
** julia.c
*/
void				julia_depth_loop(t_env *e, t_fractal *j);
void				julia_horizontal_loop(t_env *e, t_fractal *j);
void				julia_vertical_loop(t_env *e, t_fractal *j);
t_fractal			init_julia(t_env *e);

/*
** burningship.c
*/
void				burningship_depth_loop(t_env *e, t_fractal *n);
void				burningship_horizontal_loop(t_env *e, t_fractal *n);
void				burningship_vertical_loop(t_env *e, t_fractal *n);
t_fractal			init_burningship(t_env *e);

#endif
