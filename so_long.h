/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroch <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:04:48 by vroch             #+#    #+#             */
/*   Updated: 2022/02/04 14:05:06 by vroch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "./mlx/mlx.h"

struct s_map
{
	int		nbl;
	int		nbc;
	int		nb_player;
	int		nb_collectable;
	int		nb_exit;
	int		err_map;
	int		player_l;
	int		player_c;
	int		nb_pas;
	char	map[20][40];
};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_data;

typedef struct s_vars {
	void			*mlx;
	void			*mlx_win;
	struct s_map	s_map;
	struct s_data	imb;
	struct s_data	imf;
	struct s_data	imp;
	struct s_data	im2;
	struct s_data	im3;
	struct s_data	im4;
	struct s_data	im5;
	struct s_data	imc;
	struct s_data	ime;
}				t_vars;

char			*ft_itoa(int n);
struct s_map	init_s_map2(struct s_map s_map);
struct s_map	init_s_map(void);
struct s_map	trait_info(struct s_map s_map, char *line);
struct s_map	load_info(char *file);
struct s_map	check_s_map(struct s_map s_map);
struct s_map	compteurs_s_map_3(struct s_map s_map);
struct s_map	compteurs_s_map_2(struct s_map s_map);
struct s_map	compteurs_s_map(struct s_map s_map);
struct s_vars	key_trait_s(struct s_vars *vars, int new_l, int new_c);
struct s_vars	key_trait(struct s_vars *vars, int new_l, int new_c);
struct s_vars	key_gauche(struct s_vars *vars);
struct s_vars	key_bas(struct s_vars *vars);
struct s_vars	key_droit(struct s_vars *vars);
struct s_vars	key_haut(struct s_vars *vars);
int				key_hook(int keycode, t_vars *vars);
struct s_vars	load_image(struct s_vars vars);
struct s_vars	load_image_s(struct s_vars vars);
struct s_vars	aff_ber(struct s_vars vars);
struct s_vars	aff_ber_if(struct s_vars vars, int l, int c);
int				closeg(int keycode, t_vars *vars);
struct s_map	build_map(struct s_map s_map);
int				main(int argc, char **argv);

#endif
