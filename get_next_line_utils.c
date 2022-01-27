/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:27:37 by vroch             #+#    #+#             */
/*   Updated: 2021/12/23 11:07:39 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t count, size_t size)
{
	int	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	else
		gnl_bzero(ptr, count * size);
	return (ptr);
}

void	*gnl_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*strc;

	i = 0;
	strc = (unsigned char *)str;
	while (i < n)
	{
		strc[i] = 0;
		i++;
	}
	return (str = strc);
}

size_t	gnl_strlen(const char *str)
{
	unsigned long int	res;

	if (*str == 0)
		return (0);
	res = 0;
	while (str[res])
		res++;
	return (res);
}

char	*concat_line(char *static_line, char *buff, ssize_t n)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (static_line)
		i = gnl_strlen(static_line);
	j = gnl_strlen(buff);
	line = calloc(i + j + 1, 2);
	i = 0;
	if (static_line != NULL)
	{
		while (static_line[i] != '\0')
		{
			line[i] = static_line[i];
			i++;
		}
		free (static_line);
	}
	j = 0;
	if (buff != NULL)
		while (buff[j] != '\0' && n > (ssize_t)j)
			line[i++] = buff[j++];
	return (line);
}
