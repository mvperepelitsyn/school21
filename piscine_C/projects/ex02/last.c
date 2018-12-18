/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:25:01 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/07 11:47:37 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	last_word(char *str)
{
	char	*last;
	int		i;

	i = 0;
	last = &str[i];
	while (str[i])
	{
		if (!(str[i] >= 33 && str[i] <= 126))
		{
			if (str[i + 1] >= 33 && str[i + 1] <= 126)
				last = &str[i + 1];
		}
		i++;
	}
	if (last)
		ft_putstr(last);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	ft_putchar('\n');
	return (0);
}
