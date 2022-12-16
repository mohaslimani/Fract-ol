/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:40:07 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 22:34:23 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_color_1(t_fractol *data, int iter)
{
	int	rgb;

	rgb = ((255 / data->iter) + iter * 20) % 255;
	return (((rgb << 16) + (rgb << 8) + rgb));
}

int		ft_color_2(t_fractol *data, int iter)
{
	int rgb;

	rgb = 255 - ((255 / data->iter) + iter * 20) % 255;
	return (((rgb << 16) + (rgb << 8) + rgb));
}

int		ft_color_3(t_fractol *data, int iter)
{
	int	rgb;

	rgb = ((255 / data->iter) * iter) % 255;
	return (((rgb << 16) + (rgb << 8) + rgb));
}

int		ft_color_4(t_fractol *data, int iter)
{
	int	rgb;

	rgb = ((16777215 / data->iter) * iter) % 16777215;
	if (iter >= 100)
		return (0xFFFFFF);
	return (rgb);
}

int		ft_color(t_fractol *p, int iter)
{
	int	color;

	(p->color == 0) ? (color = ft_color_1(p, iter * 2)) : 0;
	(p->color == 1) ? (color = ft_color_2(p, iter)) : 0;
	(p->color == 2) ? (color = ft_color_3(p, iter)) : 0;
	(p->color == 3) ? (color = ft_color_4(p, iter)) : 0;
	(p->color == 4) ? (color = ft_color_5(p, iter)) : 0;
	(p->color == 5) ? (color = ft_color_6(p, iter)) : 0;
	(p->color == 6) ? (color = ft_color_7(p, iter)) : 0;
	(p->color == 7) ? (color = ft_color_8(p, iter)) : 0;
	(p->color == 8) ? (color = ft_color_9(p, iter)) : 0;
	(p->color == 9) ? (color = ((iter * 200 + iter) % 65025) << 4) : 0;
	return (color);
}
