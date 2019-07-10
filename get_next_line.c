/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copinto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 23:47:17 by copinto-          #+#    #+#             */
/*   Updated: 2019/07/09 19:03:32 by copinto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				v_line(int fd, char **stack, char **line)
{
	char		*j;
	int			i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i] !='\0')
		i++;
	if (stack[fd][i] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, i);
		j = ft_strdup(stack[fd][++i]);
		free(stack[fd]);
		stack[fd] = j;
	}
	else
	{
		*line = ft_strdup(stack[fd]);
		free(stack[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*file[FD_MAX];
	char			buff[BUFF_SIZE + 1];
	char			*j;
	int				regresa;

	if (fd < 0 || fd >= FD_MAX || line == NULL)
		return (-1);
	while (((regresa = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[regresa] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strnew(1);
		j = ft_strjoin(file[fd], buff);
		free(file[fd]);
		file[fd] = j;
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	if (regresa < 0)
		return (-1);
	else if (regresa == 0 && file[fd] == NULL)
	{
		free(file[fd]);
		return (0);
	}
	return (v_line(fd, file, line));
}
