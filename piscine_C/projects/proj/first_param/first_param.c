/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:51:06 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/12 19:44:20 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc < 2)
		ft_putchar('\n');
	else
	{
		i = 0;
		while (argv[1][i])
		{
			ft_putchar(argv[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
