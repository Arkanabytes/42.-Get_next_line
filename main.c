/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copinto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:55:17 by copinto-          #+#    #+#             */
/*   Updated: 2019/07/01 02:36:13 by copinto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

static void	ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int			main(int argc, char **argv)
{
	int fd;
	char *line;
	
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else 
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if 	(argc == 2)
		close(fd);
	return (0);
}


/*
{
//	int get_next_line(const int fd, char **line)
 int fd;
 
	fd = open("pepito.txt",O_RDONLY);
	printf("El FD asignado por el sistema es es:%d\n",fd);
		return (0);
}
*/
