/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertran <cbertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:03:16 by cbertran          #+#    #+#             */
/*   Updated: 2020/06/02 14:51:28 by cbertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *s, char c)
{
	char	*dest;
	int		i;

	dest = (char *)s;
	i = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	save_rest_buffer(char *buffer)
{
	char	*save;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	x = ++i;
	while (buffer[x])
		x++;
	if (!(save = (char *)malloc(sizeof(char) * x)))
		return ;
	x = 0;
	while (buffer[i])
		save[x++] = buffer[i++];
	save[x] = '\0';
	i = 0;
	while (save[i])
	{
		buffer[i] = save[i];
		i++;
	}
	free(save);
	buffer[i] = '\0';
}

char	*complete_current_line(char *buffer, char *save)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(buffer, save, 0);
	free(save);
	save = tmp;
	buffer[0] = '\0';
	return (save);
}

int		r_rest_buf(char **save, char **line, char *buf, int return_read)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(buf, '\n'))
	{
		tmp = ft_strjoin(buf, *save, 1);
		free(*line);
		*line = tmp;
		free(*save);
		save_rest_buffer(buf);
		return (1);
	}
	if (return_read < BUFFER_SIZE)
	{
		make_strjoin(buf, *save, line, 1);
		return (0);
	}
	tmp = ft_strjoin(buf, *save, 0);
	free(*save);
	*save = tmp;
	return (0);
}
