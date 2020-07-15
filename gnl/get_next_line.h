/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertran <cbertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:11:11 by cbertran          #+#    #+#             */
/*   Updated: 2020/06/01 23:59:50 by cbertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4096
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_buf
{
	int			return_read;
	char		buf[BUFFER_SIZE + 1];
}				t_buf;

char			*ft_strjoin(char const *buffer, char *save, int ifn);
int				ft_strchr(const char *s, char c);
void			save_rest_buffer(char *buffer);
char			*complete_current_line(char *buffer, char *save);
int				r_rest_buf(char **save, char **line, char *buffer, int re_r);

int				make_strjoin(char *buffer, char *save, char **line, int wyn);
void			free_line(char **line, char **save);
int				verify_value(int fd, char **line, char *buffer, char **save);
int				get_next_line(int fd, char **line);

#endif
