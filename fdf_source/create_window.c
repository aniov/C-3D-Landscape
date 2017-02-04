/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:32:53 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 16:46:44 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_in(t_env *e)
{
	int i;
	int j;
	int x0;
	int y0;

	x0 = e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].x;
	y0 = e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].y;
	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			e->matrx[i][j].x *= ZOOM;
			e->matrx[i][j].y *= ZOOM;
			e->matrx[i][j].z *= ZOOM;
			j++;
		}
		i++;
	}
	move(e, x0 - e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].x,
			y0 - e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].y);
}

static void	zoom_out(t_env *e)
{
	int i;
	int j;
	int x0;
	int y0;

	x0 = e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].x;
	y0 = e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].y;
	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			e->matrx[i][j].x /= ZOOM;
			e->matrx[i][j].y /= ZOOM;
			e->matrx[i][j].z /= ZOOM;
			j++;
		}
		i++;
	}
	move(e, x0 - e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].x,
			y0 - e->matrx[e->nr_of_lines / 2][e->nr_of_colms / 2].y);
}

int			m_zoom(t_env *e, int keycode, int button)
{
	if ((keycode == Z_OUT_1 || keycode == Z_OUT_2 || button == Z_OUT_M)
			&& (e->zoom > MIN_ZOOM))
	{
		e->zoom = e->zoom - 0.1;
		zoom_out(e);
	}
	else if ((keycode == Z_IN_1 || keycode == Z_IN_2 || button == Z_IN_M)
			&& (e->zoom < MAX_ZOOM))
	{
		e->zoom = e->zoom + 0.1;
		zoom_in(e);
	}
	mlx_clear_window(e->mlx, e->win);
	draw_dots(e);
	return (0);
}

int			key_move(t_env *e, int keycode)
{
	if (keycode == MOVE_UP_1 || keycode == MOVE_UP_2)
		move(e, 0, -MOVE);
	else if (keycode == MOVE_DOWN_1 || keycode == MOVE_DOWN_2)
		move(e, 0, MOVE);
	else if (keycode == MOVE_LEFT_1 || keycode == MOVE_LEFT_2)
		move(e, -MOVE, 0);
	else if (keycode == MOVE_RIGHT_1 || keycode == MOVE_RIGHT_2)
		move(e, MOVE, 0);
	else if (keycode == OX_ROTATE_UP || keycode == OX_ROTATE_DOWN ||
			keycode == OY_ROTATE_UP || keycode == OY_ROTATE_DOWN ||
			keycode == OZ_ROTATE_LEFT || keycode == OZ_ROTATE_RIGHT)
		rotate(e, keycode);
	else if (keycode == RESET)
		reset_pos(e);
	mlx_clear_window(e->mlx, e->win);
	draw_dots(e);
	return (0);
}

void		draw_dots(t_env *e)
{
	int lne;
	int col;

	lne = 0;
	while (lne < e->nr_of_lines)
	{
		col = 0;
		while (col < e->nr_of_colms)
		{
			if (col < e->nr_of_colms - 1)
				draw_line(e, &(e->matrx[lne][col]), &(e->matrx[lne][col + 1]));
			if (lne < e->nr_of_lines - 1)
				draw_line(e, &(e->matrx[lne][col]), &(e->matrx[lne + 1][col]));
			col++;
		}
		lne++;
	}
	print_text(e);
}
