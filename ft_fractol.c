/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:21:27 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 22:41:27 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_fractol *data, long double x, long double y, long double k)
{
	long double	x1;
	long double	y1;

	x1 = (x / IMG_WIDTH) * (data->x_max - data->x_min) + data->x_min;
	y1 = (y / IMG_WIDTH) * (data->y_max - data->y_min) + data->y_min;
	data->x_min = x1 + ((data->x_min - x1) * k);
	data->y_min = y1 + ((data->y_min - y1) * k);
	data->x_max = x1 + ((data->x_max - x1) * k);
	data->y_max = y1 + ((data->y_max - y1) * k);
	(k == 0.8) ? data->iter += 1 : data->iter--;
}

int		deal_x(int key, t_fractol *data)
{
	(void)data;
	exit(0);
	return (key);
}

char	*init_name_c(t_fractol *data)
{
	if (data->type == 10)
		return ("tricorn");
	else if (data->type == 11)
		return ("quadcorne");
	else if (data->type == 12)
		return ("quint_corne");
	else if (data->type == 13)
		return ("burningship");
	else if (data->type == 14)
		return ("rorscharch");
	else if (data->type == 15)
		return ("sphere");
	return ("");
}

char	*init_name(t_fractol *data)
{
	if (data->type == 1)
		return ("julia");
	else if (data->type == 2)
		return ("mandelbrot");
	else if (data->type == 3)
		return ("multibrot_2");
	else if (data->type == 4)
		return ("multibrot_3");
	else if (data->type == 5)
		return ("multibrot_4");
	else if (data->type == 6)
		return ("negative_mandelbrot_1");
	else if (data->type == 7)
		return ("negative_mandelbrot_2");
	else if (data->type == 8)
		return ("sierpinski_carpet");
	else if (data->type == 9)
		return ("sierpinski_triangle");
	return (init_name_c(data));
}

void	ft_fractol(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, IMG_HEIGHT, IMG_WIDTH, "fract'ol");
	data->win2 = mlx_new_window(data->mlx, MENU_H + 4,
	MENU_W + 4, "CONTROL :)");
	control(data);
	data->img_ptr = mlx_new_image(data->mlx, IMG_HEIGHT, IMG_WIDTH);
	data->img = (int*)mlx_get_data_addr(data->img_ptr, &(data->bpp),
	&(data->sline), &(data->endian));
	ft_draw(data);
	mlx_hook(data->win, 17, 0, deal_x, data);
	mlx_hook(data->win, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win2, 17, 0, deal_x, data);
	mlx_hook(data->win2, 2, 1L << 0, deal_key, data);
	if (data->pause == 0)
	{
		mlx_hook(data->win, 6, 0, mouse_move, data);
		mlx_hook(data->win2, 6, 0, mouse_move, data);
	}
	mlx_hook(data->win, 4, 1L << 2, mouse_wheel, data);
	mlx_loop(data->mlx);
}
