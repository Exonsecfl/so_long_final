/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:58:15 by vroch             #+#    #+#             */
/*   Updated: 2022/01/27 08:58:25 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* -----------------------------------------------------------------------------
 *  Remise a zero des elements de la struct s_map - tableau
 */

struct s_map	init_s_map2(struct s_map s_map)
{
	int				l;
	int				c;

	l = 0;
	c = 0;
	while (l < 20)
	{
		while (c < 40)
		{
			s_map.map[l][c] = '.';
			c++;
		}
		l++;
		c = 0;
	}
	return (s_map);
}

/* -----------------------------------------------------------------------------
 *  Remise a zero des elements de la struct s_map - fields
 */

struct s_map	init_s_map(void)

{
	struct s_map	s_map;

	(s_map).nbl = 0;
	(s_map).nbc = 0;
	s_map.nb_player = 0;
	s_map.nb_collectable = 0;
	s_map.nb_exit = 0;
	s_map.err_map = 0;
	s_map.player_l = 0;
	s_map.player_c = 0;
	s_map.nb_pas = 0;
	s_map = init_s_map2(s_map);
	return (s_map);
}
/* -----------------------------------------------------------------------------
 * Construction of the s_map. In case there is mix of lenght in map.ber
 *  the lenth of line is set as 999 (will be treated in the checks)
 *  s_map.err_map = 1 tableau non rectangulaire
 */

struct s_map	trait_info(struct s_map s_map, char *line)
{
	int				len;
	int				l;
	int				c;

	l = (s_map).nbl;
	(s_map).nbl++;
	len = gnl_strlen(line)-1;
	c = 0;
	if (len < 40 & l < 20)
	{
		while (c < len)
		{
			if (line[c] != '\n')
				(s_map).map[l][c] = line [c];
			c++;
		}
	}
	if ((s_map).nbc == 0)
		(s_map).nbc = len;
	if (len != (s_map).nbc)
	{
		(s_map).nbc = 999;
		s_map.err_map = 1;
	}
	return (s_map);
}
/* -----------------------------------------------------------------------------
 * Call get_next_line to read the map.ber file and provide the formated s_map
 */

struct s_map	load_info(char *file)
{
	struct s_map	s_map;
	int				fd;
	int				boucle;
	char			*line;

	fd = open(file, O_RDONLY);
	s_map = init_s_map();
	boucle = 0;
	while (boucle != 2)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			boucle = 2;
			free(line);
			close(fd);
		}
		else
		{
			s_map = trait_info(s_map, line);
			free(line);
		}
	}
	return ((s_map));
}
/* -----------------------------------------------------------------------------
 * Check the structure of the map.ber versus max length & width of the screen
 *  ligne requsises + de 2 et moins de 20
 *  colonnes requises + de 2 et moins de 40
 *  s_map.err_map = 2 longeur de lignes (colonne) incorrect
 *  s_map.err_map = 3 nb de lignes incorrect
 */

struct s_map	check_s_map(struct s_map s_map)
{
	if ((s_map).nbc > 40 || (s_map).nbc < 2)
	{
		s_map.err_map = 2;
		return (s_map);
	}
	if ((s_map).nbl < 2 || (s_map).nbl > 20)
	{
		s_map.err_map = 3;
		return (s_map);
	}
	return (s_map);
}
