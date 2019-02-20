/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_pos.h"
#include "ft_check_args.h"
#include "ft_print.h"
#include "ft_back_tracking.h"

int		main(int argc, char **argv)
{
	int	table[9][9];
	int	solution[9][9];
	int	count;

	count = 0;
	if (!ft_check_args(argc, argv))
		ft_putstr("Error\n");
	else
	{
		ft_transform(argv + 1, &table);
		ft_back_tracking(table, &count, &solution);
		if (count == 1)
			ft_print_table(solution);
		else
			ft_putstr("Error\n");
	}
	return (0);
}
