/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:19:06 by mvoina            #+#    #+#             */
/*   Updated: 2016/01/12 19:22:20 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		m_size(char *str)
{
	int size;

	size = 0;
	while (str[size] != '\n' && str[size] != '\0')
		size++;
	return (size);
}

static char		*next_line(char **str)
{
	char	*new_line;
	char	*temp;
	int		i;

	temp = *str;
	i = 0;
	if (**str == '\n')
	{
		(*str)++;
		return (0);
	}
	if ((new_line = (char*)malloc((m_size(temp) + 1) * sizeof(char))) == 0)
		return (0);
	while (i < m_size(temp))
	{
		new_line[i] = **str;
		(*str)++;
		i++;
	}
	new_line[i] = '\0';
	if (**str != '\0')
		(*str)++;
	return (new_line);
}

static char		*make_str(int fd, int *res)
{
	int			count;
	char		*buff;
	char		*temp;
	char		*str;

	str = 0;
	count = 1;
	if ((buff = (char*)malloc((BUFF_SIZE + 1) * sizeof(char))) == 0)
		return (0);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while ((*res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((temp = (char*)malloc((BUFF_SIZE * count + 1) * sizeof(char))) == 0)
			return (0);
		ft_memset(temp, '\0', BUFF_SIZE * count + 1);
		if (str != 0)
			ft_strncpy(temp, str, BUFF_SIZE * count);
		str = temp;
		ft_strncat(str, buff, BUFF_SIZE);
		count++;
		ft_memset(buff, '\0', BUFF_SIZE + 1);
	}
	return (str);
}

static int		ret_nr(char *str, char **line, int *result)
{
	if (*result < 0)
	{
		*line = 0;
		*result = -1;
		return (1);
	}
	if (str == 0)
	{
		*line = 0;
		*result = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			result;
	static char *str;

	result = 0;
	if (line == 0 || fd < 0)
		return (-1);
	if (str == 0)
		str = make_str(fd, &result);
	if (ret_nr(str, line, &result))
		return (result);
	if (*str == '\0')
		return (0);
	*line = next_line(&str);
	if (*str == 0)
		str = 0;
	if (*line == 0)
		return (1);
	return (1);
}
