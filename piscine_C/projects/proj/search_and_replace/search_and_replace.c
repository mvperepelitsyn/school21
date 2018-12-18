/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:03:46 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/12 21:22:32 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_find(char *str, char a, char b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			ft_putchar(b);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[3][1] == '\0' && argv[2][1] == '\0')
			ft_find(argv[1], argv[2][0], argv[3][0]);
	}
	ft_putchar('\n');
	return (0);
}
