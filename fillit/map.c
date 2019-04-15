/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:32:06 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/10 13:43:09 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_clean_map(char **map, char let)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == let)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

char		**ft_new_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		ft_exit();
	map[size] = NULL;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * size)))
			ft_exit();
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

void		ft_print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char		**ft_copy_map(char **map, int size)
{
	int		i;
	int		j;
	char	**mt_map;

	i = 0;
	mt_map = ft_new_map(size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] != '.')
				mt_map[i][j] = map[i][j];
			j++;
		}
		mt_map[i][j] = '\0';
		i++;
	}
	mt_map[i] = NULL;
	ft_freemap(map, size);
	return (mt_map);
}

void		ft_freemap(char **map, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_strdel(&map[j]);
		j++;
	}
	free(map);
}
