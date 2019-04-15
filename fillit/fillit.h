/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:26:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/11 19:55:07 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef struct		s_tetr
{
	char		name;
	t_point		coord[4];
}					t_tetr;

typedef struct		s_atetr
{
	int			min;
	char		**map;
	char		count;
	t_tetr		tetr[26];
	t_point		start;
	t_point		middle;
}					t_atetr;

int					main(int argc, char **argv);
int					ft_algo_rec(t_atetr *mtetr, t_point posit, char **map,
		int iter);
int					ft_does_it_fit(char **map, t_point start, t_tetr *tetra);
int					ft_check_conn(t_atetr *mtetr, int	nbr);
char				**ft_new_map(int size);
char				**ft_copy_map(char **map, int size);
void				ft_create_tetr_coord(t_atetr *mtetr, int ct, int i,
		int num);
void				ft_algo(t_atetr *mtetr);
void				ft_put_tetr(char **map, t_point start, t_tetr *tetra);
void				ft_clean_map(char **map, char let);
void				ft_print_map(char **map);
void				ft_exit(void);
void				ft_open_tetr(char *argv, t_atetr *mtetr);
void				ft_read_tetr(int fd, t_atetr *mtetr);
void				ft_init_tetr(int nbr_name, t_atetr *mtetr);
void				ft_create_tetr(char *str, int nbr, t_atetr *mtetr);
void				ft_check_tetr(t_atetr *mtetr, int nbr);
void				ft_check_tetr_form(t_atetr *mtetr, int nbr);
void				ft_move_coord(t_atetr *mtetr, int nbr);
void				ft_freemap(char **map, int i);
t_point				ft_give_next_point(t_point start, char **map);
t_point				ft_new_point(t_point point, int x, int y);

#endif
