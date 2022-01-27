/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map_compteurs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:05:40 by vroch             #+#    #+#             */
/*   Updated: 2022/01/27 09:05:43 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* -----------------------------------------------------------------------------
 * Check the structure of the map.ber (collectable, player, exit)
 *  s_map.err_map = 8 au moins un collectable
 *  s_map.err_map = 9 1 seul player autorise
 *  s_map.err_map = 10 au moins un exit
 */

struct s_map	compteurs_s_map_3(struct s_map s_map)
{
	if (s_map.nb_collectable < 1)
		s_map.err_map = 8;
	if (s_map.nb_player != 1)
		s_map.err_map = 9;
	if (s_map.nb_exit < 1)
		s_map.err_map = 10;
	return (s_map);
}
/* -----------------------------------------------------------------------------
 * Check the structure of the map.ber (collectable, player, exit)
 */

struct s_map	compteurs_s_map_2(struct s_map s_map)
{
	int					l;
	int					c;

	l = 0;
	c = 0;
	while (l <= (s_map).nbl)
	{
		while (c <= (s_map).nbc)
		{
			if ((s_map).map[l][c] == 'C')
				(s_map).nb_collectable++;
			if ((s_map).map[l][c] == 'E')
				(s_map).nb_exit++;
			if ((s_map).map[l][c] == 'P')
			{
				(s_map).nb_player++;
				s_map.player_c = c;
				s_map.player_l = l;
			}
			c++;
		}
		c = 0;
		l++;
	}
	return (s_map);
}
/* -----------------------------------------------------------------------------
 * Check the structure of the map.ber (wall, player, exit)
 *	s_map.err_map = 4 erreur ligne top qui doit etre a 1
 *  s_map.err_map = 5 erreur ligne bas qui doit etre a 1
 *  s_map.err_map = 6 erreur colonne 0 qui doit etre a 1
 *  s_map.err_map = 7 erreur colonne fin qui doit etre a 1
 *  s_map.err_map = 8 au moins un collectable
 *  s_map.err_map = 9 1 seul player autorise
 *  s_map.err_map = 10 au moins un exit
 */

struct s_map	compteurs_s_map(struct s_map s_map)
{
	int					l;
	int					c;

	l = 0;
	c = 0;
	while (l <= (s_map).nbl)
	{
		while (c <= (s_map).nbc)
		{
			if (l == 0 && c < s_map.nbc && (s_map).map[l][c] != '1')
				s_map.err_map = 4;
			if (l == s_map.nbl - 1 && c < s_map.nbc && (s_map).map[l][c] != '1')
				s_map.err_map = 5;
			if (c == 0 && l < s_map.nbl && s_map.map[l][c] != '1')
				s_map.err_map = 6;
			if (c == s_map.nbc - 1 && l < s_map.nbl && (s_map).map[l][c] != '1')
				s_map.err_map = 7;
			c++;
		}
		c = 0;
		l++;
	}
	(s_map) = compteurs_s_map_2(s_map);
	(s_map) = compteurs_s_map_3(s_map);
	return (s_map);
}
