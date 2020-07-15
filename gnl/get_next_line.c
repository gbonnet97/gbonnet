/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertran <cbertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:03:06 by cbertran          #+#    #+#             */
/*   Updated: 2020/06/01 23:56:03 by cbertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		make_strjoin(char *buffer, char *save, char **line, int wyn)
{
	char	*tmp;

	tmp = NULL;
	if (wyn == 0)
	{
		tmp = ft_strjoin(buffer, save, 1);
		free_line(line, &tmp);
		free(save);
		if (BUFFER_SIZE > 1)
			save_rest_buffer(buffer);
		return (1);
	}
	else if (wyn == 1)
	{
		tmp = ft_strjoin(buffer, save, 0);
		free_line(line, &tmp);
		save[0] = '\0';
	}
	else if (wyn == 2)
	{
		free(*line);
		*line = save;
	}
	return (0);
}

void	free_line(char **line, char **tmp)
{
	free(*line);
	*line = *tmp;
}

int		verify_value(int fd, char **line, char *buf, char **save)
{
	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || (read(fd, buf, 0) < 0)
			|| !(*save = (char *)malloc(sizeof(char)))
			|| !(*line = (char *)malloc(sizeof(char))))
		return (1);
	*save[0] = '\0';
	*line[0] = '\0';
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	val;
	char			*save;

	if (verify_value(fd, line, val.buf, &save))
		return (-1);
	if ((val.buf[0] != '\0' && BUFFER_SIZE > 1)
			&& (r_rest_buf(&save, line, val.buf, val.return_read)))
		return (1);
	while ((val.return_read = read(fd, val.buf, BUFFER_SIZE)) > 0)
	{
		val.buf[val.return_read] = '\0';
		if (ft_strchr(val.buf, '\n'))
			return (make_strjoin(val.buf, save, line, 0));
		if (val.return_read < BUFFER_SIZE)
			make_strjoin(val.buf, save, line, 1);
		else
			save = complete_current_line(val.buf, save);
	}
	if (BUFFER_SIZE == 1 || (val.return_read == 0 && save[0] != '\0'))
		make_strjoin(val.buf, save, line, 2);
	else if (BUFFER_SIZE > 1 && save[0] == '\0')
		free(save);
	return (0);
}
