/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:58:21 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/02/20 17:53:55 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fillit.h"
#include <stdio.h>

static	int		how_many_cells(char	*str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*str)
	{
		if ((*str == '#' || *str == '.') && count < 4)
		{
			if (*str == '#')
				i++;
		}
		else
			return (-1);
		count++;
		str++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int 	i;

	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = i + how_many_cells(line);
		free(line);
	}
	if (i != 4)
	{
		printf("It's not a valid file\n");
		return (0);
	}
	printf("I found %d of '#' in this file\n", i);
	close(fd);
}
