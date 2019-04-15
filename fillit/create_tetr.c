/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:40 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/11 19:54:52 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_tetr(int nbr_name, t_atetr *mtetr)
{
	int		i;

	i = 0;
	mtetr->tetr[nbr_name].name = nbr_name + 65;
	while (i < 4)
	{
		mtetr->tetr[nbr_name].coord[i].x = -1;
		mtetr->tetr[nbr_name].coord[i].y = -1;
		i++;
	}
}

void		ft_create_tetr_coord(t_atetr *mtetr, int ct, int i, int num)
{
	mtetr->tetr[num].coord[ct].x = i % 5;
	mtetr->tetr[num].coord[ct].y = i / 5;
}

void		ft_create_tetr(char *str, int nbr, t_atetr *mtetr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	ft_init_tetr(nbr, mtetr);
	while (i < 20)
	{
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			ft_exit();
		if (str[i] == '.' || str[i] == '\n')
			;
		else if (str[i] == '#' && count < 4)
		{
			ft_create_tetr_coord(mtetr, count, i, nbr);
			count++;
		}
		else
			ft_exit();
		i++;
	}
	if (nbr != 0 && str[i] != '\n')
		ft_exit();
	ft_check_tetr(mtetr, nbr);
}
