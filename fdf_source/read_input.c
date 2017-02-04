/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:03:39 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 18:04:42 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_dots(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	key_move(e, keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (x == y)
		x = y;
	m_zoom(e, 0, button);
	return (0);
}

void	print_text(t_env *e)
{
	char	*str;
	int		y;

	y = 50;
	str = ft_itoa(e->zoom);
	mlx_string_put(e->mlx, e->win, 50, y - 10, C_GREEN, "Commands:");
	mlx_string_put(e->mlx, e->win, 50, y + 20, C_COMANDS, "Zoom in/out:");
	mlx_string_put(e->mlx, e->win, 175, y + 20, C_GREEN, "Scroll");
	mlx_string_put(e->mlx, e->win, 50, y + 40, C_COMANDS, K_MOVE);
	mlx_string_put(e->mlx, e->win, 294, y + 40, C_GREEN, "Keyboard Arrows");
	mlx_string_put(e->mlx, e->win, 50, y + 60, C_COMANDS, K_ROTATE);
	mlx_string_put(e->mlx, e->win, 185, y + 60, C_GREEN, "W-A-S-D and < >");
	mlx_string_put(e->mlx, e->win, 50, y + 80, C_COMANDS, R_POS);
	mlx_string_put(e->mlx, e->win, 204, y + 80, C_GREEN, "F1");
	mlx_string_put(e->mlx, e->win, 50, y + 100, C_COMANDS, "Iesire:");
	mlx_string_put(e->mlx, e->win, 125, y + 100, C_GREEN, "Esc");
	mlx_string_put(e->mlx, e->win, 50, y + 130, C_WHITE, "ZOOM:");
	mlx_string_put(e->mlx, e->win, 120, y + 130, C_WHITE, str);
}
