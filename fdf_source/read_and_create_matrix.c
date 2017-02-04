/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_create_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:30:01 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 18:02:55 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_ini_scale(t_env *e)
{
	int max;

	if (e->nr_of_lines > e->nr_of_colms)
		max = e->nr_of_lines;
	else
		max = e->nr_of_colms;
	e->scale = INI_WINDOW / max;
}

static void		initialize_matrx(char *line, int line_nr, t_env *e)
{
	char	**str;
	int		col;

	col = 0;
	str = ft_strsplit(line, ' ');
	while (col < e->nr_of_colms)
	{
		e->matrx[line_nr][col].z = ft_atoi(str[col]) * e->scale / 10;
		e->matrx[line_nr][col].y = line_nr * e->scale + 150;
		e->matrx[line_nr][col].x = col * e->scale + 500;
		e->matrx[line_nr][col].ini_z = e->matrx[line_nr][col].z;
		e->matrx[line_nr][col].ini_y = e->matrx[line_nr][col].y;
		e->matrx[line_nr][col].ini_x = e->matrx[line_nr][col].x;
		col++;
	}
}

static void		nr_of_lines(char *map, t_env *e)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		lines++;
	close(fd);
	if (lines == 0)
	{
		ft_putstr("Error reading Map\nThe map doesn't exist or is empty\n");
		exit(0);
	}
	e->nr_of_lines = lines;
}

static void		ft_words(char const *s, t_env *e)
{
	int i;
	int wo;
	int flag;

	i = 0;
	wo = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' && s[i] != '\0')
			i++;
		flag = 0;
		while (s[i] != ' ' && s[i] != '\0')
		{
			i++;
			flag = 1;
		}
		if (flag)
			wo++;
	}
	e->nr_of_colms = wo;
}

void			read_and_create_matrix(int argc, char **argv, t_env *e,
				int flag)
{
	int		fd;
	char	*line;
	char	*map;
	int		line_nr;

	line_nr = 0;
	map = argv[1];
	if (argc == 1)
		map = "maps/42.fdf";
	nr_of_lines(map, e);
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (flag)
		{
			ft_words(line, e);
			e->matrx = (t_point**)malloc(e->nr_of_lines * sizeof(t_point*));
			calc_ini_scale(e);
			flag = 0;
		}
		e->matrx[line_nr] = (t_point*)malloc(e->nr_of_colms * sizeof(t_point));
		initialize_matrx(line, line_nr, e);
		line_nr++;
	}
	close(fd);
}
