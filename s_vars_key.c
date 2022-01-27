/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vars_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:11:29 by vroch             #+#    #+#             */
/*   Updated: 2022/01/27 09:11:33 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_vars	key_trait_s(struct s_vars *vars, int new_l, int new_c)
{
	vars->s_map.map[vars->s_map.player_l][vars->s_map.player_c] = '0';
	vars->s_map.map[new_l][new_c] = 'P';
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imf.img,
		(vars->s_map.player_c) * 64, (vars->s_map.player_l) * 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->im2.img,
		new_c * 64, new_l * 64);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imf.img,
		new_c * 64, new_l * 64);
	if (new_c > vars->s_map.player_c)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imp.img,
			new_c * 64, new_l * 64);
	else if (new_c < vars->s_map.player_c)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->im2.img,
			new_c * 64, new_l * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->im3.img,
			new_c * 64, new_l * 64);
	vars->s_map.player_c = new_c;
	vars->s_map.player_l = new_l;
	vars->s_map.nb_pas++;
}

/* -----------------------------------------------------------------------------
 *  Key treatment
 *   based on parameter new_l and new_c for next position
 *   and s_map.player_l and s_map.player_c
 *   redefinition of past position
 *   and next position
 *  Specific traitement for
 * 	 C collectable
 *   E exit & nb collectable with 0 value required for exit
 */

struct s_vars	key_trait(struct s_vars *vars, int new_l, int new_c)
{
	if (vars->s_map.map[new_l][new_c] == 'C')
	{
		vars->s_map.map[new_l][new_c] = '0';
		vars->s_map.nb_collectable = vars->s_map.nb_collectable - 1;
	}
	if (vars->s_map.map[new_l][new_c] == 'E' && vars->s_map.nb_collectable == 0)
	{
		vars->s_map.map[new_l][new_c] = '0';
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit (0);
	}
	if (vars->s_map.map[new_l][new_c] == '0')
	{
		vars = key_trait_s(vars, new_l, new_c);
		printf("\n compteur de pas : %d ", vars->s_map.nb_pas);
		mlx_string_put(vars->mlx, vars->mlx_win, 20, 20, 0x0000FF00,
			"Nb. de pas : ");
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imb.img,
			2 * 64, 0 * 64);
		mlx_string_put(vars->mlx, vars->mlx_win, 130, 20, 0x0000FF00,
			(ft_itoa(vars->s_map.nb_pas)));
	}
	return (*vars);
}
