/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:58:21 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/02/19 16:29:40 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		x;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((x = get_next_line(fd, &line)) == 1)
	{
		
		printf("Return value =  %d\n", x);
		ft_putendl(line);
		free(line);
	}
	x = get_next_line(fd, &line);
	printf("Return value =  %d\n", x);
	ft_putendl(line);
	free(line);
	close(fd);
}
