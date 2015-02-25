/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:01:40 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/25 14:19:54 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include "../libft/libft.h"

# define ITERATION_MANDELBROT_X 800
# define ITERATION_MANDELBROT_Y 700
# define ITERATION_MANDELBROT_Z 15

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
	int				color;
}					t_mandelbrot;

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

void		ft_depth_loop(t_env *e, t_mandelbrot *m);
void		ft_horizontal_loop(t_env *e, t_mandelbrot *m);
void		ft_vertical_loop(t_env *e, t_mandelbrot *m);
void		display_mandelbrot(t_env *e);

#endif