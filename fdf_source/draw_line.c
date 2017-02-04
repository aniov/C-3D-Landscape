/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:47:35 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 17:00:39 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

void			draw_line(t_env *e, t_point *p1, t_point *p2)
{
	double	max_xy;
	double	ind;
	float	max_dif;
	double	x01;
	double	y01;

	max_dif = ft_max(fabs(p2->x - p1->x), fabs(p2->y - p1->y));
	ind = 0;
	while (ind <= max_dif)
	{
		x01 = p1->x + ind / max_dif * (p2->x - p1->x);
		y01 = p1->y + ind / max_dif * (p2->y - p1->y);
		max_xy = ft_max(x01 - p1->x, y01 - p1->y);
		mlx_pixel_put(e->mlx, e->win, x01, y01,
				calc_color(max_dif, max_xy, p1, p2));
		ind++;
	}
}
