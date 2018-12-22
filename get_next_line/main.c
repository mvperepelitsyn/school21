/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:20:27 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/19 19:13:41 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;
	int		result;

	if (argc > 0)
	{
		line = NULL;
		if (argc == 1)
		{
			fd = 0;
			fd2 = 0;
		}
		else
		{
			fd = open(argv[1], O_RDONLY);
			fd2 = dup2(fd, 1000);
		}
		while ((result = get_next_line(fd2, &line)) >= 0)
		{
			ft_putnbr(result);
			ft_putstr(": ");
			ft_putstr(line);
			free(line);
			if (result == 0)
			{
				close(fd);
				return (0);
			}
			ft_putchar('\n');
		}
		close(fd);
	}
	else
		return (1);
	return (0);
}
