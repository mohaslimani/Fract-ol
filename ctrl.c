/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:29:02 by msoulaim          #+#    #+#             */
/*   Updated: 2020/11/27 20:31:44 by msoulaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		square_fill(t_fractol *data, int color, t_coord pos, t_coord size)
{
	int		i;
	int		j;

	i = pos.x - 1;
	while (++i < size.x)
	{
		j = pos.y - 1;
		while (++j < size.y)
			mlx_pixel_put(data->mlx, data->win2, i, j, color);
	}
}

void		square_str(t_fractol *data, char *str, t_coord pos, t_coord size)
{
	t_coord	t;

	t.x = pos.x + (pos.x + size.x) / 2 - (ft_strlen(str) * 12) / 2;
	t.y = (size.y - pos.y) / 3 + pos.y - 3;
	mlx_string_put(data->mlx, data->win2, t.x, t.y, 0x000000, str);
}

void		ctrl_name(t_fractol *data)
{
	square_fill(data, 0xF9AA33, (t_coord){14, 77}, (t_coord){242, 127});
	square_str(data, data->name, (t_coord){14, 77}, (t_coord){242, 127});
}

void		ctrl_1(t_fractol *data)
{
	char	*tmp;

	tmp = ft_itoa(data->color);
	mlx_string_put(data->mlx, data->win2, 260, 10, 0xFF00FF, "EXIT:   ESC");
	mlx_string_put(data->mlx, data->win2, 260, 30, 0xFF00FF, "MOVE:");
	mlx_string_put(data->mlx, data->win2, 260, 30, 0xF9AA33, "      UP");
	mlx_string_put(data->mlx, data->win2, 260, 50, 0xF9AA33, "LEFT    RIGHT");
	mlx_string_put(data->mlx, data->win2, 260, 70, 0xF9AA33, "     DOWN  ");
	mlx_string_put(data->mlx, data->win2, 260, 90, 0xFF00FF, "ZOOM in center:");
	mlx_string_put(data->mlx, data->win2, 260, 110,
											0xF9AA33, "minus(-) plus(+)");
	mlx_string_put(data->mlx, data->win2, 260, 130,
											0xFF00FF, "next/prev fractal:");
	mlx_string_put(data->mlx, data->win2, 260, 150, 0xF9AA33, "       T/Y");
	mlx_string_put(data->mlx, data->win2, 260, 170, 0xFF00FF, "color :");
	mlx_string_put(data->mlx, data->win2, 260, 170,
											0xF9AA33, "        C : ");
	mlx_string_put(data->mlx, data->win2, 380, 170,
											0xFFAAFF, tmp);
	mlx_string_put(data->mlx, data->win2, 260, 190,
											0xFF00FF, "depth(sphere) :");
	mlx_string_put(data->mlx, data->win2, 260, 210,
											0xF9AA33, "      TAB");
	mlx_string_put(data->mlx, data->win2, 260, 250, 0xF9AA33, "      R");
	free(tmp);
}

void		control(t_fractol *data)
{
	char	*tmp;

	square_fill(data, 0x434955, (t_coord){3, 3}, (t_coord){MENU_H, MENU_W});
	square_fill(data, 0x232F34, (t_coord){252, 0}, (t_coord){254, MENU_W});
	square_fill(data, 0x232F34, (t_coord){0, 199}, (t_coord){253, 201});
	square_fill(data, 0x232F34, (t_coord){127, 200}, (t_coord){129, MENU_W});
	ctrl_name(data);
	ctrl_1(data);
	mlx_string_put(data->mlx, data->win2, 260,
										230, 0xFF00FF, "RESET FRACTAL :");
	mlx_string_put(data->mlx, data->win2, 10, 215, 0xFF00FF, "iteration:");
	if (data->type == 8)
		tmp = ft_itoa(data->iter_sponge);
	else if (data->type == 9)
		tmp = ft_itoa(data->iter_s);
	else
		tmp = ft_itoa(data->iter);
	mlx_string_put(data->mlx, data->win2, 50, 235, 0xF9AA33, tmp);
	free(tmp);
	mlx_string_put(data->mlx, data->win2, 10, 235, 0xF9AA33, "(W)    (S)");
	mlx_string_put(data->mlx, data->win2, 132, 215, 0xFF00FF, "track_mouse:");
	if (data->pause == 1)
		mlx_string_put(data->mlx, data->win2, 177, 235, 0xFFAAFF, "no");
	else
		mlx_string_put(data->mlx, data->win2, 177, 235, 0xFFAAFF, "yes");
}
