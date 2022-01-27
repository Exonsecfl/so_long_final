/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vars_refresh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:19:49 by vroch             #+#    #+#             */
/*   Updated: 2022/01/27 09:20:09 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* -----------------------------------------------------------------------------
 *  gestion des commandes clavier en entree
 *	53=Esc
 *  0=a & 123	= fleche gauche
 *  1=s & 125	= fleche bas
 *  2=d & 124	= fleche droite
 *  13=w & 1236	= fleche haut
 */

int	key_hook(int keycode, t_vars *vars)
{
	vars->s_map.nb_pas++;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (keycode == 0 || keycode == 123)
		*vars = key_gauche(vars);
	if (keycode == 1 || keycode == 125)
		*vars = key_bas(vars);
	if (keycode == 2 || keycode == 124)
		*vars = key_droit(vars);
	if (keycode == 13 || keycode == 126)
		*vars = key_haut(vars);
	return (0);
}

/* -----------------------------------------------------------------------------
 * Load image files
 */

struct s_vars	load_image(struct s_vars vars)
{
	int	img_w;
	int	img_h;

	vars.imb.img = mlx_xpm_file_to_image(vars.mlx, "X_Brown.xpm", &img_w,
			&img_h);
	vars.imf.img = mlx_xpm_file_to_image(vars.mlx, "X_Green.xpm", &img_w,
			&img_h);
	vars.imc.img = mlx_xpm_file_to_image(vars.mlx, "X_Collectible.xpm", &img_w,
			&img_h);
	vars.ime.img = mlx_xpm_file_to_image(vars.mlx, "X_End.xpm", &img_w,
			&img_h);
	vars.imp.img = mlx_xpm_file_to_image(vars.mlx, "X_Player_1.xpm", &img_w,
			&img_h);
	vars.im2.img = mlx_xpm_file_to_image(vars.mlx, "X_Player_2.xpm", &img_w,
			&img_h);
	vars.im3.img = mlx_xpm_file_to_image(vars.mlx, "X_Player_3.xpm", &img_w,
			&img_h);
	vars.im4.img = mlx_xpm_file_to_image(vars.mlx, "X_Player_4.xpm", &img_w,
			&img_h);
	vars.im5.img = mlx_xpm_file_to_image(vars.mlx, "X_Player_5.xpm", &img_w,
			&img_h);
	return (vars);
}
/* -----------------------------------------------------------------------------
 * Suite Load image files
 */

struct s_vars	load_image_s(struct s_vars vars)
{
	vars.imb.addr = mlx_get_data_addr(vars.imb.img, &vars.imb.bpp,
			&vars.imb.line_l, &vars.imb.endian);
	vars.imf.addr = mlx_get_data_addr(vars.imf.img, &vars.imf.bpp,
			&vars.imf.line_l, &vars.imf.endian);
	vars.imc.addr = mlx_get_data_addr(vars.imc.img, &vars.imc.bpp,
			&vars.imc.line_l, &vars.imc.endian);
	vars.ime.addr = mlx_get_data_addr(vars.ime.img, &vars.ime.bpp,
			&vars.ime.line_l, &vars.ime.endian);
	vars.imp.addr = mlx_get_data_addr(vars.imp.img, &vars.imp.bpp,
			&vars.imp.line_l, &vars.imp.endian);
	vars.im2.addr = mlx_get_data_addr(vars.imp.img, &vars.imp.bpp,
			&vars.imp.line_l, &vars.imp.endian);
	vars.im3.addr = mlx_get_data_addr(vars.imp.img, &vars.imp.bpp,
			&vars.imp.line_l, &vars.imp.endian);
	vars.im4.addr = mlx_get_data_addr(vars.imp.img, &vars.imp.bpp,
			&vars.imp.line_l, &vars.imp.endian);
	vars.im5.addr = mlx_get_data_addr(vars.imp.img, &vars.imp.bpp,
			&vars.imp.line_l, &vars.imp.endian);
	return (vars);
}
/* -----------------------------------------------------------------------------
 * Affiche .ber map avec les image files
 */

struct s_vars	aff_ber(struct s_vars vars)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (l < vars.s_map.nbl)
	{
		while (c < vars.s_map.nbc)
		{
			if (vars.s_map.map[l][c] == '1')
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imb.img,
					c * 64, l * 64);
			if (vars.s_map.map[l][c] == '0')
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imf.img,
					c * 64, l * 64);
			if (vars.s_map.map[l][c] == 'P')
			{
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imf.img,
					c * 64, l * 64);
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imp.img,
					c * 64, l * 64);
			}
			if (vars.s_map.map[l][c] == 'C')
			{
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imf.img,
					c * 64, l * 64);
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imc.img,
					c * 64, l * 64);
			}
			if (vars.s_map.map[l][c] == 'E')
			{
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.imf.img,
					c * 64, l * 64);
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.ime.img,
					c * 64, l * 64);
			}
			c++;
		}
		l++;
		c = 0;
	}
	return (vars);
}
