/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:25:02 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 17:25:42 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_env *e)
{
	ini_env(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "fdf-42-project");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
}

void	ini_env(t_env *e)
{
	e->zoom = 1;
	ini_color(e);
	rotate(e, -1);
}

void	reset_pos(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			e->matrx[i][j].z = e->matrx[i][j].ini_z;
			e->matrx[i][j].y = e->matrx[i][j].ini_y;
			e->matrx[i][j].x = e->matrx[i][j].ini_x;
			j++;
		}
		i++;
	}
	e->zoom = 1;
	rotate(e, -1);
}
