/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:01:40 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 16:39:15 by nschilli         ###   ########.fr       */
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
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 700
# define DEPTH_MANDELBROT 15
# define DEPTH_JULIA 300

typedef struct		s_mandelbrot
{
	int				x;
	int				y;
	int				a;
	float			rc;
	float			ic;
	float			minX;
	float			minY;
	float			maxX;
	float			maxY;
}					t_mandelbrot;

typedef struct		s_julia
{
	int				x;
	int				y;
	int				a;
	float			rc;
	float			ic;
	float			newre;
	float			newim;
	float			oldre;
	float			oldim;
	float			zoom;
	float			moveX;
	float			moveY;
}					t_julia;

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
	int 			bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*fractol;
	t_image			i;
}					t_env;

/*
** display.c
*/

void			ft_put_pixel_to_image(t_image *i, int x, int y, t_color color);
void			ft_display(t_env *e);
int				key_hook(int keycode);
int				expose_hook(t_env *e);
void			ft_init(char *fractol);

/*
** mandelbrot.c
*/

void			mandelbrot_choose_color(t_mandelbrot *m, t_color *color);
void			mandelbrot_depth_loop(t_env *e, t_mandelbrot *m);
void			mandelbrot_horizontal_loop(t_env *e, t_mandelbrot *m);
void			mandelbrot_vertical_loop(t_env *e, t_mandelbrot *m);
void			display_mandelbrot(t_env *e);

/*
** julia.c
*/

void			julia_depth_loop(t_env *e, t_julia *j);
void			julia_horizontal_loop(t_env *e, t_julia *j);
void			julia_vertical_loop(t_env *e, t_julia *j);
void			display_julia(t_env *e);

#endif