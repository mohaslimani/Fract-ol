/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:16:05 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 23:05:22 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color_5(t_fractol *data, int iter)
{
	int rgb;

	rgb = ((255 / data->iter) * iter) % 255;
	return ((120 << 16) + (rgb << 8));
}

int		ft_color_6(t_fractol *data, int iter)
{
	int rgb;

	if (iter >= data->iter)
		return (0xFF00FF);
	rgb = (iter * iter * iter * 10) % 0xFFFFFF;
	if (data->type == 1)
		return (iter * 200);
	return (rgb);
}

int		ft_color_7(t_fractol *data, int iter)
{
	int rgb;

	if (iter >= data->iter)
		return (0x0FF0aa);
	rgb = ((iter * iter * iter - iter * iter + 15)) % 0xFFFFFF;
	return (rgb);
}

int		ft_color_8(t_fractol *data, int iter)
{
	int rgb;

	if (iter >= data->iter)
		return (0xFF00aa);
	rgb = ((iter * 15 + iter) << 16) + iter * 20 + iter * 2;
	return (rgb % 0xFFFFFF);
}

int		ft_color_9(t_fractol *data, int iter)
{
	int rgb;

	if (iter >= data->iter)
		return (0x0000FF);
	iter = iter % 10;
	rgb = iter + iter * 10 + iter * 1000 + iter * 100000 + iter * 1000000;
	return (rgb);
}
