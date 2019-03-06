/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_print_table(int table[9][9])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			ft_putchar(table[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
