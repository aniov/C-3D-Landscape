/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:01:23 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 19:16:22 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	e;
	int		flag;

	flag = 1;
	read_and_create_matrix(argc, argv, &e, flag);
	create_window(&e);
	return (0);
}
