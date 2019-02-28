/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_tracking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "ft_check_pos.h"

void	ft_transform(char **argv, int (*res)[9][9])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (argv[i][j] == '.')
				(*res)[i][j] = 0;
			else
				(*res)[i][j] = argv[i][j] - '0';
		}
	}
}

void	ft_copy_array(int table[9][9], int (*dest)[9][9])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
			(*dest)[i][j] = table[i][j];
	}
}

void	ft_back_tracking(int table[9][9], int *count, int (*res)[9][9])
{
	int	row;
	int	col;
	int	i;

	if (-1 == ft_find_cell(table))
	{
		(*count)++;
		ft_copy_array(table, res);
	}
	else
	{
		row = ft_find_cell(table) / 10;
		col = ft_find_cell(table) % 10;
		i = 0;
		while (++i <= 9)
		{
			if (ft_check(table, row, col, i))
			{
				table[row][col] = i;
				ft_back_tracking(table, count, res);
				table[row][col] = 0;
			}
		}
	}
}
