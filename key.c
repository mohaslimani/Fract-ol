/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:03:39 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 20:26:55 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reinitialise(t_fractol *data)
{
	data->speed = 0.8;
	data->iter = 50;
	data->iter_sponge = 2;
	data->y_max = 2.0;
	data->x_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
}

void	events(t_fractol *data, int key)
{
	if (key == KEY_P)
		data->pause = (data->pause + 1) % 2;
	if (key == KEY_T || key == KEY_Y)
	{
		ft_reinitialise(data);
		if (key == KEY_T)
			data->type = (data->type == FRACTAL) ? 1 : data->type + 1;
		else
			data->type = (data->type == 1) ? FRACTAL : data->type - 1;
		data->name = init_name(data);
	}
	if (key == KEY_C)
		data->color = (data->color + 1) % 10;
	if (key == KEY_W)
	{
		data->iter++;
		data->iter_sponge++;
	}
	if (key == KEY_S)
	{
		data->iter--;
		(data->iter_sponge > 0) ? data->iter_sponge-- : 0;
	}
	control(data);
}

void	zoom_in_out(t_fractol *data, int key)
{
	if (key == KEY_PLUS)
	{
		ft_zoom(data, IMG_WIDTH / 2.0, IMG_WIDTH / 2.0, 0.8);
		data->speed *= 0.8;
		data->zoom_s *= 0.8;
		if (data->zoom_s <= 0.5)
			data->zoom_s = 1;
	}
	if (key == KEY_MINUS)
	{
		ft_zoom(data, IMG_WIDTH / 2.0, IMG_WIDTH / 2.0, 1.0 / 0.8);
		data->speed *= 1.0 / 0.8;
		(data->zoom_s <= 4) ? (data->zoom_s *= 1.0 / 0.8) : 0;
	}
	if (key == KEY_PLUS || key == KEY_MINUS)
		control(data);
}

void	move(t_fractol *data, int key)
{
	if (key == KEY_RIGHT)
	{
		data->x_min += 0.2 * data->speed;
		data->x_max += 0.2 * data->speed;
		data->moove_x += 10;
	}
	if (key == KEY_LEFT)
	{
		data->x_min -= 0.2 * data->speed;
		data->x_max -= 0.2 * data->speed;
		data->moove_x = (data->moove_x - 10 > 0) ? data->moove_x - 10 : 0;
	}
	if (key == KEY_UP)
	{
		data->y_min -= 0.2 * data->speed;
		data->y_max -= 0.2 * data->speed;
		data->moove_y = (data->moove_y - 10 > 0) ? data->moove_y - 10 : 0;
	}
	if (key == KEY_DOWN)
	{
		data->y_min += 0.2 * data->speed;
		data->y_max += 0.2 * data->speed;
		data->moove_y = data->moove_y + 10;
	}
}

int		deal_key(int key, t_fractol *data)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == KEY_R)
		ft_reinitialise(data);
	if (key == KEY_TAB)
		data->var = data->var + 1;
	if (key == KEY_MINUS || key == KEY_PLUS)
		zoom_in_out(data, key);
	if (key >= 123 && key <= 126)
		move(data, key);
	if (key == KEY_P || key == KEY_T || key == KEY_Y ||
	key == KEY_C || key == KEY_W || key == KEY_S)
		events(data, key);
	ft_draw(data);
	return (key);
}
