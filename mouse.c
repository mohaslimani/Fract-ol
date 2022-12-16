/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 04:04:55 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 22:28:18 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_fractol *p)
{
	if (p->pause == 0)
	{
		p->jul_re = p->x_min + ((p->x_max - p->x_min) / IMG_WIDTH) * x;
		p->jul_im = p->y_min + ((p->y_max - p->y_min) / IMG_WIDTH) * y;
	}
	ft_draw(p);
	return (0);
}

void	spong_zoom(int button, t_fractol *data)
{
	if (data->zoom <= 0.3 && button == 5)
	{
		data->iter_sponge = (data->iter_sponge >= 9) ?
		8 : data->iter_sponge + 1;
		data->zoom = 1;
	}
	if (data->zoom <= 0.3 && button == 4)
	{
		data->iter_sponge = (data->iter_sponge <= 1) ?
		1 : data->iter_sponge - 1;
		data->zoom = 1;
	}
}

int		mouse_wheel(int button, int x, int y, t_fractol *data)
{
	if (button == 5)
	{
		ft_zoom(data, x, y, 0.8);
		data->speed *= 0.8;
		data->zoom *= 0.8;
		spong_zoom(5, data);
	}
	else if (button == 4)
	{
		ft_zoom(data, x, y, 1.0 / 0.8);
		data->speed *= 1.0 / 0.8;
		data->zoom *= 1.0 / 0.8;
		spong_zoom(4, data);
	}
	control(data);
	ft_draw(data);
	return (button);
}
