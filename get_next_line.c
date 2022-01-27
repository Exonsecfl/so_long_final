/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:27:11 by vroch             #+#    #+#             */
/*   Updated: 2021/12/23 11:14:48 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			return (i);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

char	*split_line_debut(char *static_line, char *debut)
{
	size_t	i;
	char	*line;

	i = (gnl_strlen(static_line));
	line = gnl_calloc(i, 2);
	i = 0;
	while (static_line[i] != '\0')
	{
		if (static_line[i] == '\n')
		{
			line[i] = static_line[i];
			free (debut);
			return (line);
		}
		line[i] = static_line[i];
		i++;
	}
	free (debut);
	return (line);
}

char	*split_line_fin(char *static_line)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = (gnl_strlen(static_line));
	line = gnl_calloc(i, 2);
	i = 0;
	while (static_line[i] != '\n' && static_line[i] != '\0')
		i++;
	j = 0;
	if (static_line[i] == '\n')
		i++;
	else
		i = 0;
	while (static_line[i] != '\0')
	{
		line[j] = static_line[i];
		j++;
		i++;
	}
	free(static_line);
	return (line);
}

char	*gnl_01(ssize_t n, char *buff, char *debut)
{
	static char	*static_line;

	if (n != 0)
		static_line = concat_line (static_line, buff, n);
	if ((static_line && gnl_strlen(static_line) && n == 0) || (n != 0))
	{
		if (search_new_line(static_line) != 0)
		{
			debut = split_line_debut(static_line, debut);
			static_line = split_line_fin(static_line);
			return (debut);
		}
		else if (n == 0)
		{
			debut = split_line_fin(static_line);
			static_line = NULL;
			return (debut);
		}
	}
	free (debut);
	if (n == 0)
		free (static_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		n;
	char		*vreturn;
	char		*debut;

	n = 1;
	debut = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) == -1) || fd < -1)
		return (NULL);
	while (n != 0)
	{
		n = read (fd, buff, BUFFER_SIZE);
		vreturn = gnl_01(n, buff, debut);
		if (vreturn != NULL)
			return (vreturn);
	}
	return (NULL);
}
