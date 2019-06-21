/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copinto- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 23:47:17 by copinto-          #+#    #+#             */
/*   Updated: 2019/06/15 00:07:46 by copinto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strjoin(const char *s1, const char *s2);

static char			*ft_strdup(const char *str);

static int			valid_line(char **stk, char **linea);
{
	char		*puntero;
	char		*temporal;
	int			iterador;

	iterador = 0;
	puntero = *stk;
	while (puntero[iterador] != '\n')
	{
		if (puntero[iterador] == '\0')
			return (0);
		else
			iterador++;
	}
	temporal = &puntero[iterador];
	*temporal = '\0';
	*stk = ft_strdup(temporal + 1);
	*linea = ft_strdup(puntero);
	free(puntero);
	puntero = NULL;
	return (1);
}

static int			read_file(int fd, char *hp, char **stk, char **linea)
{
	int				devuelve;
	char			*puntero;

	while ((devuelve = read(fd, hp, BUFF_SIZE)) > 0)
	{
		hp[devuelve] = '\0';
		if (*stk)
		{
			puntero = *stk;
			*stk = ft_strjoin(puntero, hp);
			free(puntero);
			puntero = NULL;
		}
		else
			*stk = ft_strdup(hp);
		if (valid_line(stk, linea))
			break ;
	}
	if (devuelve > 0)
		return (1);
	return (devuelve);
}

int					get_next_line(int fd, char **linea)
{
	static char		*stk[DESCRIPTORS];
	char			*hp;
	int				devuelve;
	int				iterador;

	iterador = 0;
	if (!line || fd < 0 || fd >= DESCRIPTORS || (read(fd, stk[fd], 0) < 0) \
			|| !(hp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stk[fd])
		if (valid_line(&stk[fd], linea))
			return (1);
	while (iterador < BUFF_SIZE)
		hp[iterador++] = '\0';
	devuelve = read_file(fd, hp, &stk[fd], linea);
	free(hp);
	if (devuelve != 0 || stk[fd] == NULL || stk[fd][0] == '\0')
	{
		if (devuelve == 0 && *linea)
			*linea = NULL;
		return (devuelve);
	}
	*linea = stk[fd];
	stk[fd] = NULL;
	return (1);
}
