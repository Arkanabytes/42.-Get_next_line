/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copinto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:55:17 by copinto-          #+#    #+#             */
/*   Updated: 2019/06/14 19:26:01 by copinto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

static void		ft_putendl(char *str)
{
	int			itr;

	itr = 0;
	while (str[itr])
	{
		write(1, &str[itr], 1);
		itr++;
	}
	write(1,"\n", 1);
}

int				main(int ac, char **av)
{
	int			fd;
	char		*linea;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	while (gext_next_line(fd, &line) == 1)
	{
		ft_putendl(linea);
		free(linea);
	}
	if (ac == 2)
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
