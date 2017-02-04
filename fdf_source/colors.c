/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:28:22 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 16:32:34 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int				set_table_color(char *color_table, char col)
{
	color_table[3] = '\0';
	color_table[0] = 255;
	color_table[1] = 255;
	color_table[2] = 255;
	if (col == 'r')
	{
		color_table[0] = 0;
		color_table[1] = 0;
	}
	return (*(int*)(color_table));
}

static int				add_color(char c, char *base_color, int add)
{
	unsigned char point_color[4];

	point_color[3] = '\0';
	if (c == 'r')
	{
		point_color[0] = base_color[0] - add;
		point_color[1] = base_color[1] - add;
		point_color[2] = 255;
	}
	else if (c == 'w')
	{
		point_color[0] = base_color[0] + add;
		point_color[1] = base_color[1] + add;
		point_color[2] = 255;
	}
	return ((*(int*)point_color));
}

static unsigned char	substract_color(char *color1, char *color2)
{
	unsigned char dif;

	dif = color1[0] - color2[0];
	color1[3] = '\0';
	color2[3] = '\0';
	return (dif);
}

int						calc_color(int x_dif, int x_pos,
									t_point *p1, t_point *p2)
{
	unsigned int col;
	unsigned int seg;

	x_pos = ft_abs(x_pos);
	x_dif = ft_abs(x_dif);
	if ((*(int*)p1->color) == (*(int*)p2->color))
		return ((*(int*)p1->color));
	else if ((*(int*)p1->color) > (*(int*)p2->color))
	{
		seg = substract_color((void*)p1->color, (void*)p2->color) / (x_dif + 1);
		col = add_color('r', (void*)p1->color, seg * x_pos);
	}
	else
	{
		seg = substract_color((void*)p2->color, (void*)p1->color) / (x_dif + 1);
		col = add_color('w', (void*)p1->color, seg * x_pos);
	}
	return (col);
}

void					ini_color(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->nr_of_lines)
	{
		j = 0;
		while (j < e->nr_of_colms)
		{
			if (e->matrx[i][j].z > 0)
				set_table_color((void*)e->matrx[i][j].color, 'r');
			else
				set_table_color((void*)e->matrx[i][j].color, 'w');
			j++;
		}
		i++;
	}
}
