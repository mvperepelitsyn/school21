/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:30:59 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/10 13:45:21 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_algo_rec(t_atetr *mtetr, t_point posit, char **map, int iter)
{
	if (iter == mtetr->count)
		return (1);
	if (posit.x < 0)
		return (0);
	if (ft_does_it_fit(map, posit, &mtetr->tetr[iter]))
	{
		ft_put_tetr(map, posit, &mtetr->tetr[iter]);
		if (ft_algo_rec(mtetr, ft_new_point(mtetr->middle, 0, 0),
					map, iter + 1))
			return (1);
		ft_clean_map(map, mtetr->tetr[iter].name);
	}
	return (ft_algo_rec(mtetr, ft_give_next_point(posit, map), map, iter));
}

void	ft_algo(t_atetr *mtetr)
{
	char	**map;

	mtetr->start = ft_new_point(mtetr->start, 0, 0);
	mtetr->middle = ft_new_point(mtetr->middle, 0, 0);
	mtetr->min = 2;
	map = ft_new_map(mtetr->min);
	while (!(ft_algo_rec(mtetr, mtetr->start, map, 0)))
	{
		ft_freemap(map, mtetr->min);
		mtetr->min++;
		map = ft_new_map(mtetr->min);
	}
	mtetr->map = ft_copy_map(map, mtetr->min);
}
