/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vars_fleche.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:25:31 by vroch             #+#    #+#             */
/*   Updated: 2022/01/27 13:28:51 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* -----------------------------------------------------------------------------
 *  Fleche gauche
 */

struct s_vars	key_gauche(struct s_vars *vars)
{
	int	new_l;
	int	new_c;

	new_l = vars->s_map.player_l;
	new_c = vars->s_map.player_c - 1;
	key_trait(vars, new_l, new_c);
	return (*vars);
}
/* -----------------------------------------------------------------------------
 *  Fleche bas
 */

struct s_vars	key_bas(struct s_vars *vars)
{
	int	new_l;
	int	new_c;

	new_l = vars->s_map.player_l + 1;
	new_c = vars->s_map.player_c;
	key_trait(vars, new_l, new_c);
	return (*vars);
}

/* -----------------------------------------------------------------------------
 *  Fleche droite
 */

struct s_vars	key_droit(struct s_vars *vars)
{
	int	new_l;
	int	new_c;

	new_l = vars->s_map.player_l;
	new_c = vars->s_map.player_c + 1;
	key_trait(vars, new_l, new_c);
	return (*vars);
}
/* -----------------------------------------------------------------------------
 *  Fleche haut
 */

struct s_vars	key_haut(struct s_vars *vars)
{
	int	new_l;
	int	new_c;

	new_l = vars->s_map.player_l - 1;
	new_c = vars->s_map.player_c;
	key_trait(vars, new_l, new_c);
	return (*vars);
}
