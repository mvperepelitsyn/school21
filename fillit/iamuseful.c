/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somestuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:32:46 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/10 13:39:58 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		ft_new_point(t_point point, int x, int y)
{
	point.x = x;
	point.y = y;
	return (point);
}

int			ft_does_it_fit(char **map, t_point start, t_tetr *tetra)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!(map[start.y + (tetra->coord[i]).y])
				|| !(map[start.y + (tetra->coord[i]).y]
					[start.x + (tetra->coord[i]).x]))
			return (0);
		if (((start.y + tetra->coord[i].y >= 0)
					|| (start.x + tetra->coord[i].x >= 0))
				&& (map[start.y + (tetra->coord[i]).y]
					[start.x + (tetra->coord[i]).x] != '.'))
			return (0);
		i++;
	}
	return (1);
}

void		ft_put_tetr(char **map, t_point start, t_tetr *tetra)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[start.y + (tetra->coord[i]).y][start.x + (tetra->coord[i]).x] =
			tetra->name;
		i++;
	}
}

t_point		ft_give_next_point(t_point start, char **map)
{
	int	i;
	int	j;

	i = start.y;
	j = start.x + 1;
	start = ft_new_point(start, -1, -1);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '.')
			{
				start.x = j;
				start.y = i;
				return (start);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (start);
}
