/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:26:52 by vroch             #+#    #+#             */
/*   Updated: 2021/12/23 11:03:54 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line(int fd);
void	*gnl_calloc(size_t count, size_t size);
void	*gnl_bzero(void *str, size_t n);
size_t	gnl_strlen(const char *str);
char	*concat_line(char *static_line, char *buff, ssize_t n);

#endif
