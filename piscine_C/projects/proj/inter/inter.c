/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:07:19 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/13 16:21:56 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		find(char a, char *str, int count)
{
	int		i;

	i = 0;
	while (str[i] && i < count)
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (find(argv[1][i], argv[2], ft_strlen(argv[2])))
				if (!(find(argv[1][i], argv[1], i)))
					ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
