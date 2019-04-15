/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:19 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/11 19:53:17 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_check_tetr(t_atetr *mtetr, int nbr)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (mtetr->tetr[nbr].coord[i].x < 0
				|| mtetr->tetr[nbr].coord[i].x > 3
				|| mtetr->tetr[nbr].coord[i].y < 0
				|| mtetr->tetr[nbr].coord[i].y > 3)
			ft_exit();
		i++;
	}
	ft_move_coord(mtetr, nbr);
	ft_check_tetr_form(mtetr, nbr);
}

int				ft_check_conn(t_atetr *mtetr, int nbr)
{
	int		i;
	int		j;
	int		conn;
	t_point	*cd;

	i = 0;
	conn = 0;
	cd = mtetr->tetr[nbr].coord;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((cd[i].x + 1 == cd[j].x && cd[i].y == cd[j].y)
					|| (cd[i].x - 1 == cd[j].x && cd[i].y == cd[j].y)
					|| (cd[i].x == cd[j].x && cd[i].y + 1 == cd[j].y)
					|| (cd[i].x == cd[j].x && cd[i].y - 1 == cd[j].y))
				conn++;
			j++;
		}
		i++;
	}
	return (conn);
}

void			ft_check_tetr_form(t_atetr *mtetr, int nbr)
{
	int			conn;

	conn = ft_check_conn(mtetr, nbr);
	if (conn != 6 && conn != 8)
		ft_exit();
}

void			ft_move_coord(t_atetr *mtetr, int nbr)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = mtetr->tetr[nbr].coord[0].x;
	y = mtetr->tetr[nbr].coord[0].y;
	while (i < 4)
	{
		mtetr->tetr[nbr].coord[i].x = mtetr->tetr[nbr].coord[i].x - x;
		mtetr->tetr[nbr].coord[i].y = mtetr->tetr[nbr].coord[i].y - y;
		i++;
	}
}
