/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_row(int table[9][9], int row, int num)
{
	int	col;

	col = -1;
	while (++col < 9)
		if (table[row][col] == num)
			return (0);
	return (1);
}

int		ft_check_col(int table[9][9], int col, int num)
{
	int	row;

	row = -1;
	while (++row < 9)
		if (table[row][col] == num)
			return (0);
	return (1);
}

int		ft_check_square(int table[9][9], int sq_row, int sq_col, int num)
{
	int	row;
	int	col;

	row = -1;
	while (++row < 3)
	{
		col = -1;
		while (++col < 3)
			if (table[row + sq_row][col + sq_col] == num)
				return (0);
	}
	return (1);
}

int		ft_check(int table[9][9], int row, int col, int num)
{
	return (ft_check_row(table, row, num) && ft_check_col(table, col, num) &&
		ft_check_square(table, row - row % 3, col - col % 3, num));
}

int		ft_find_cell(int table[9][9])
{
	int	row;
	int	col;

	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
			if (table[row][col] == 0)
				return (row * 10 + col);
	}
	return (-1);
}
