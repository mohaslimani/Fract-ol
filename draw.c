/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:43:08 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 20:08:10 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_fractol *data, int x, int y, int color)
{
	if (x < IMG_HEIGHT && x >= 0 && y >= 0 && y < IMG_WIDTH)
		data->img[x + y * (int)IMG_HEIGHT] = color;
}

void		draw_fractal(t_fractol *data, int b, int a)
{
	(data->type == 1) ? (put_pixel(data, b, a, julia(data, b, a))) : 0;
	(data->type == 2) ? (put_pixel(data, b, a, mandelbrot(data, b, a))) : 0;
	(data->type == 3) ? (put_pixel(data, b, a, multibrot_2(data, b, a))) : 0;
	(data->type == 4) ? (put_pixel(data, b, a, multibrot_3(data, b, a))) : 0;
	(data->type == 5) ? (put_pixel(data, b, a, multibrot_4(data, b, a))) : 0;
	(data->type == 6) ? (put_pixel(data, b, a,
	negative_mandelbrot_1(data, b, a))) : 0;
	(data->type == 7) ? (put_pixel(data, b, a,
	negative_mandelbrot_2(data, b, a))) : 0;
	(data->type == 8) ? (put_pixel(data, b, a,
	sierpinski_carpet(data, b, a))) : 0;
	(data->type == 9) ? (put_pixel(data, b, a,
	sierpinski_triangle(data, b, a))) : 0;
	(data->type == 10) ? (put_pixel(data, b, a, tricorn(data, b, a))) : 0;
	(data->type == 11) ? (put_pixel(data, b, a, quadcorne(data, b, a))) : 0;
	(data->type == 12) ? (put_pixel(data, b, a, quint_corne(data, b, a))) : 0;
	(data->type == 13) ? (put_pixel(data, b, a, burningship(data, b, a))) : 0;
	(data->type == 14) ? (put_pixel(data, b, a, rorscharch(data, b, a))) : 0;
	(data->type == 15) ? (put_pixel(data, b, a, sphere(data, b, a))) : 0;
}

void		calcul_fractal(t_fractol *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < (int)IMG_WIDTH)
	{
		y = (int)(data->order * THRED_HEIGHT);
		while (y < (int)((data->order + 1) * THRED_HEIGHT))
		{
			draw_fractal(data, (long double)y, (long double)x);
			y++;
		}
		x++;
	}
	pthread_exit(NULL);
}

void		ft_multithred(t_fractol *data)
{
	pthread_t	thread[NBTHRED];
	t_fractol	div[NBTHRED];
	int			i;

	i = 0;
	while (i < NBTHRED)
	{
		ft_memcpy((void*)&div[i], (void*)data, sizeof(t_fractol));
		div[i].order = i;
		pthread_create(&thread[i], NULL, (void*)calcul_fractal, &div[i]);
		i++;
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}

void		ft_draw(t_fractol *data)
{
	ft_bzero(data->img, (int)IMG_HEIGHT * (int)IMG_WIDTH * 4);
	ft_multithred(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
}
