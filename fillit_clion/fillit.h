/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:26:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define NAME "../valid_test1"

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
	int			count;
	t_tetr		**tetr;
}					t_atetr;

int 	main(int argc, char **argv);
int     howmanytetr(int fd);
int     ft_checkconn(char *str);
int     ft_checksym(char *str);
void	printstructs(t_atetr **mtetr);
void	ft_read(int fd, t_atetr **mtetr);
void	maketetr(char *str, t_atetr **mtetr, int j);
void    move_coord(t_atetr **mtetr, int k);
//void    move_minusy(t_atetr **mtetr, int i);
//void    move_minusx(t_atetr **mtetr, int i);



#endif
