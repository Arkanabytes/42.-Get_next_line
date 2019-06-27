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

 static char         *ft_strjoin(const char *s1, const char *s2);
 
 static char         *ft_strdup(const char *str);

// declaro validacion de lineas
static valid_line(char **stack, char **linea);
// declaro tres variables 
{
	int		*ptr;
	char	*tmp;
	char	i;
// declaro la funciones y las inicializo
	i = 0;
	ptr = *stack;
// recorre el puntero indexado mostrara el salto de linea
while(ptr[i]) != '\n')
{
	if(ptr[i] == '\0')
	else 
		i++;
}
tmp = &ptr[i];
tmp = '\0';

//funcion alocada en memoria por una copia de cadenas s1,
//La copia devuelve un puntero, el puntero en subsecuencia usadp en
// un argumento la funcion free que libera memoria.
*stack = ft_strdup(tmp + 1);
*line = ft_strdup(ptr);
free(ptr);
ptr = NULL;
return (1);
}

static		lec_file(int fd, char *hp, char **stack, char **line)
{
	// declaro las variables
	int		re;
	char	*ptr;
	//mediante un while recorro y la declaro lectura 
	while ((re = read(fd,hp,BUFF_SIZE))) > 0)
	{
	hp[re] = '\0'; // declaro el hip y lo itero y le doy con null
	*stack = ft_strjoin(ptr, hp);
	free(ptr); // libera la memoria que contiene el puntero
	ptr = NULL; // puntero lo declaro como nulo
	}
	else
		*stack = ft_strdup(hp);
		if (re > 0)
		return (1);
		return (re);
 	}

// funcion gnl
int		gnl(int fd, char **linea)
{
	//declaro tres variables
	static char *stack[DESCRIPTORS];
	char		*hp;
	int			re;
	int 		i;
}

i = 0;
//Condicion de no linea no fd es menor a cero
if (!line || fd < 0 || fd >= DESCRIPTORS || (read(fd, stack[fd], 0) < 0) \ 
|| ! (hp = (char *)malloc(sizeof(char)* BUFF_SIZE + 1)))
return (-1);
if (stack[fd])
	if(valid_line(&stack[fd], linea))
	return (1);
while (i < BUFF_SIZE)
		hp[i++] = '\0';
	re = read_file(fd, hp, &stack[fd], linea);
	free(hp);
	if (re != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (re == 0 && *linea)
			*linea = NULL;
		return (re);
	}
	*linea = stack[fd];
	stack[fd] = NULL;
	return (1);
}
