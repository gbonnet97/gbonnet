/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertran <cbertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:50:52 by cbertran          #+#    #+#             */
/*   Updated: 2020/06/02 15:42:13 by cbertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	size++;
	while (size > 0)
		str[--size] = 0;
	return (str);
}

static size_t	ft_strlen(const char *s)
{
	unsigned long int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char			*ft_strjoin(char const *buffer, char *save, int ifn)
{
	char	*malloc;
	char	*temp;

	malloc = ft_strnew(ft_strlen(buffer) + ft_strlen(save));
	temp = malloc;
	if (malloc == NULL)
		return (NULL);
	while (*buffer != (ifn > 0 ? '\n' : '\0'))
	{
		*temp = *buffer;
		buffer++;
		temp++;
	}
	while (*save != '\0')
	{
		*temp = *save;
		save++;
		temp++;
	}
	return (malloc);
}
