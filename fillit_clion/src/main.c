/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:58:21 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:18 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	int		fd;
	t_atetr	*mtetr;

	/*
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	*/
	fd = open(NAME, O_RDONLY);
	mtetr = (t_atetr *)malloc(sizeof(t_atetr));
	mtetr->count = howmanytetr(fd);
	close(fd);											//??
	ft_putstr("How many tetraminos? ");
	ft_putnbr(mtetr->count);
	ft_putchar('\n');
	if (mtetr->count < 0)
	{
		ft_putstr("It's not a valid file\n");
		return (0);
	}
	mtetr->tetr = (t_tetr **)malloc(sizeof(t_tetr) * mtetr->count);
	//fd = open(argv[1], O_RDONLY);
	fd = open(NAME, O_RDONLY);
	ft_read(fd, &mtetr);
	printstructs(&mtetr);
	free(mtetr->tetr);
	close(fd);
	return (0);
}
