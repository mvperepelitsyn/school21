/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:36:45 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/12 22:09:00 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		mini_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int i;
	int l;

	i = 0;
	if (argc == 2)
	{
		l = ft_strlen(argv[1]);
		i = mini_atoi(argv[1]);
		while (argv[1][i])
		{
			if (i == l || argv[1][i] == ' ' || argv[1][i] == '\t' ||
					argv[1][i] == '\0')
			{
				ft_putchar('\n');
				return (0);
			}
			ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
