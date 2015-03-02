/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:40:57 by nschilli          #+#    #+#             */
/*   Updated: 2015/03/02 14:29:38 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_hook(int keycode, t_env *e)
{
	// printf("%d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65451)
		ft_zoom(e);
	if (keycode == 65453)
		ft_dezoom(e);
	return (0);
}

int			mouse_hook(int mousecode, int x, int y, t_env *e)
{
	if (mousecode == 4)
		ft_zoom(e);
	if (mousecode == 5)
		ft_dezoom(e);
}

int			mouse_hook_position(int x, int y, t_env *e)
{
	e->mouse.x = ((float)x - ( WIDTH / 2)) / (WIDTH / 2);
	e->mouse.y = ((float)y - ( HEIGHT / 2)) / (HEIGHT / 2);

	if (ft_strcmp(e->fractol, "julia") == 0)
	{
		e->j.rc += e->mouse.x / WIDTH;
		e->j.ic += e->mouse.y / HEIGHT;
	}
}

int			expose_hook(t_env *e)
{
	return (0);
}