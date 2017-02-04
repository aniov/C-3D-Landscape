/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:05:38 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 19:14:54 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move(t_env *e, int ox, int oy)
{
	int i;
	int j;

	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			e->matrx[i][j].x += ox;
			e->matrx[i][j].y += oy;
			j++;
		}
		i++;
	}
}

void		set_angle(t_env *e, int keycode)
{
	e->angle.x = 0;
	e->angle.y = 0;
	e->angle.z = 0;
	if (keycode == OX_ROTATE_UP)
		e->angle.x = RADIAN_ANGLE;
	else if (keycode == OX_ROTATE_DOWN)
		e->angle.x = -RADIAN_ANGLE;
	else if (keycode == OY_ROTATE_UP)
		e->angle.y = RADIAN_ANGLE;
	else if (keycode == OY_ROTATE_DOWN)
		e->angle.y = -RADIAN_ANGLE;
	else if (keycode == OZ_ROTATE_LEFT)
		e->angle.z = RADIAN_ANGLE;
	else if (keycode == OZ_ROTATE_RIGHT)
		e->angle.z = -RADIAN_ANGLE;
	else
	{
		e->angle.z = -2 * RADIAN_ANGLE;
		e->angle.x = -3 * RADIAN_ANGLE;
		e->angle.y = 1 * RADIAN_ANGLE;
	}
}

void		concatenate_matrices(t_env *e)
{
	double temp[3][3];

	helper_matrix_ini(e);
	multiply_matrix(e->mat.x, e->mat.y, temp);
	multiply_matrix(temp, e->mat.z, e->mat.r);
}

static void	make_the_math(t_env *e, int i, int j)
{
	double xyz[3];
	double nx;
	double ny;
	double nz;

	xyz[0] = e->matrx[i][j].x - e->xmid;
	xyz[1] = e->matrx[i][j].y - e->ymid;
	xyz[2] = e->matrx[i][j].z;
	nx = e->mat.r[0][0] * xyz[0] + e->mat.r[0][1] * xyz[1] + e->mat.r[0][2]
		* xyz[2];
	ny = e->mat.r[1][0] * xyz[0] + e->mat.r[1][1] * xyz[1] + e->mat.r[1][2]
		* xyz[2];
	nz = e->mat.r[2][0] * xyz[0] + e->mat.r[2][1] * xyz[1] + e->mat.r[2][2]
		* xyz[2];
	e->matrx[i][j].x = nx + e->xmid;
	e->matrx[i][j].y = ny + e->ymid;
	e->matrx[i][j].z = nz;
}

void		rotate(t_env *e, int keycode)
{
	int i;
	int j;
	int c;
	int l;

	l = e->nr_of_lines - 1;
	c = e->nr_of_colms - 1;
	e->xmid = (e->matrx[l][c].x - e->matrx[0][0].x) / 2 + e->matrx[0][0].x;
	e->ymid = (e->matrx[l][c].y - e->matrx[0][0].y) / 2 + e->matrx[0][0].y;
	set_angle(e, keycode);
	concatenate_matrices(e);
	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			make_the_math(e, i, j);
			j++;
		}
		i++;
	}
}
