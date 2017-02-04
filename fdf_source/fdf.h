/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:02:03 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 19:09:38 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include "key_def.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_mat
{
	double			x[3][3];
	double			y[3][3];
	double			z[3][3];
	double			r[3][3];
}					t_mat;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	unsigned char	color[4];
	double			ini_x;
	double			ini_y;
	double			ini_z;
	double			ini_color;
}					t_point;

typedef struct		s_angle
{
	double			x;
	double			y;
	double			z;
}					t_angle;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				nr_of_lines;
	int				nr_of_colms;
	double			xmid;
	double			ymid;
	double			zoom;
	t_angle			angle;
	int				scale;
	t_mat			mat;
	t_point			**matrx;
}					t_env;

void				read_and_create_matrix(int argc, char **argv, t_env *e,
					int flag);
void				print_matrx(t_env *e);
void				draw_dots(t_env *e);
void				create_window(t_env *e);
int					key_hook(int keycode, t_env *e);
int					key_move(t_env *e, int keycode);
int					mouse_hook(int button, int x, int y, t_env *e);
int					m_zoom(t_env *e, int keycode, int button);
int					expose_hook(t_env *e);
void				ini_env(t_env *e);
void				move(t_env *e, int ox, int oy);
void				reset_pos(t_env *e);
void				print_text(t_env *e);
void				draw_line(t_env *e, t_point *p1, t_point *p2);
void				ini_color(t_env *e);
int					calc_color(int x_dif, int x_pos, t_point *p1, t_point *p2);
void				rotate(t_env *e, int keycode);
void				helper_matrix_ini(t_env *e);
void				multiply_matrix(double m1[3][3], double m2[3][3],
					double m3[3][3]);
void				set_angle(t_env *e, int keycode);
void				concatenate_matrices(t_env *e);

#endif
