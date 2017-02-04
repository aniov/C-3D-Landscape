/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:16:44 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 17:18:16 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	helper_matrix_ini_x(t_env *e)
{
	e->mat.x[0][0] = 1.0f;
	e->mat.x[0][1] = 0.0f;
	e->mat.x[0][2] = 0.0f;
	e->mat.x[1][0] = 0.0f;
	e->mat.x[1][1] = cosf(e->angle.x);
	e->mat.x[1][2] = sinf(e->angle.x);
	e->mat.x[2][0] = 0.0f;
	e->mat.x[2][1] = -sinf(e->angle.x);
	e->mat.x[2][2] = cosf(e->angle.x);
}

static void	helper_matrix_ini_y(t_env *e)
{
	e->mat.y[0][0] = cosf(e->angle.y);
	e->mat.y[0][1] = 0.0f;
	e->mat.y[0][2] = -sinf(e->angle.y);
	e->mat.y[1][0] = 0.0f;
	e->mat.y[1][1] = 1.0f;
	e->mat.y[1][2] = 0.0f;
	e->mat.y[2][0] = sinf(e->angle.y);
	e->mat.y[2][1] = 0.0f;
	e->mat.y[2][2] = cosf(e->angle.y);
}

static void	helper_matrix_ini_z(t_env *e)
{
	e->mat.z[0][0] = cosf(e->angle.z);
	e->mat.z[0][1] = sinf(e->angle.z);
	e->mat.z[0][2] = 0.0f;
	e->mat.z[1][0] = -sinf(e->angle.z);
	e->mat.z[1][1] = cosf(e->angle.z);
	e->mat.z[1][2] = 0;
	e->mat.z[2][0] = 0.0f;
	e->mat.z[2][1] = 0.0f;
	e->mat.z[2][2] = 1.0f;
}

void		helper_matrix_ini(t_env *e)
{
	helper_matrix_ini_x(e);
	helper_matrix_ini_y(e);
	helper_matrix_ini_z(e);
}

void		multiply_matrix(double first_mat[3][3], double scnd_mat[3][3],
		double result_mat[3][3])
{
	double	temp;
	int		a;
	int		b;
	int		c;

	a = 0;
	temp = 0;
	while (a < 3)
	{
		b = 0;
		while (b < 3)
		{
			c = 0;
			while (c < 3)
			{
				temp += first_mat[b][c] * scnd_mat[c][a];
				c++;
			}
			result_mat[b][a] = temp;
			temp = 0;
			b++;
		}
		a++;
	}
}
