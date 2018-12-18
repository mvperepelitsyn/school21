/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:22:11 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/12 21:02:37 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		count(char c)
{
	int repeat;

	if (c >= 65 && c <= 90)
		repeat = c - 65 + 1;
	else if (c >= 97 && c <= 122)
		repeat = c - 97 + 1;
	else
		repeat = 1;
	return (repeat);
}

int		main(int argc, char **argv)
{
	int i;
	int r;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			r = count(argv[1][i]);
			while (r--)
				ft_putchar(argv[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
