/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:08:19 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/12 19:41:44 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int k;
	int i;

	k = 0;
	i = 0;
	if (argc > 1)
	{
		while (argv[k])
			k++;
		while (argv[k - 1][i])
		{
			ft_putchar(argv[k - 1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
