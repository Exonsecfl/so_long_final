/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:45:53 by vroch             #+#    #+#             */
/*   Updated: 2022/01/16 13:45:57 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* -----------------------------------------------------------------------------
 *
 */
int	closeg(int keycode, t_vars *vars)
{
	(void)	keycode;
	(void)	vars;
	exit(0);
}
/* -----------------------------------------------------------------------------
 * Affiche la map
 *  store collectable number
 */

struct s_map	build_map(struct s_map s_map)
{
	void			*mlx;
	void			*mlx_win;
	int				width;
	int				height;
	struct s_vars	vars;

	width = 64 * (s_map).nbc;
	height = 64 * (s_map).nbl;
	mlx = mlx_init();
	vars.mlx = mlx;
	mlx_win = mlx_new_window(mlx, width, height, "So Long");
	vars.mlx_win = mlx_win;
	vars.s_map = s_map;
	vars = load_image(vars);
	vars = load_image_s(vars);
	vars = aff_ber(vars);
	mlx_key_hook(mlx_win, key_hook, &vars);
	mlx_hook(mlx_win, 17, 0L << 0, closeg, &vars);
	mlx_loop(mlx);
	return (s_map);
}
/* -----------------------------------------------------------------------------
 * main of so_long
 */

int	main(int argc, char **argv)
{
	struct s_map	s_map;

	if (argc != 2)
	{
		write (1, "Parametre MAP.ber manquant", 26);
		return (0);
	}
	s_map = load_info(argv[1]);
	s_map = check_s_map (s_map);
	s_map = compteurs_s_map(s_map);
	if (s_map.err_map == 0)
	{
		(s_map) = build_map(s_map);
	}
	else
	{
		printf ("\nnb ligne %d", s_map.nbl);
		printf ("\nlen ligne %d", s_map.nbc);
		printf ("\nnb player %d", s_map.nb_player);
		printf ("\nnb collect %d", s_map.nb_collectable);
		printf ("\nnb exit %d", s_map.nb_exit);
		printf ("\nerr_map %d", s_map.err_map);
		printf("le fichier %s est incorrect / inexistant", argv[1]);
		printf ("\nerr_map %d", s_map.err_map);
	}
}
