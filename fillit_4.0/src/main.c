/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:58:21 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/06 15:59:27 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fillit.h"
#include <stdio.h>

static void		maketetr(char *str, t_tetr *tetr)
{
	size_t	x;
	size_t	y;
	size_t	l;

	x = 0;
	y = 0;
	l = 0;
	while (*str)
	{
		while (*str != '\n')
		{
			if (*str == '#')
			{
				tetr->coord[l].x = x;
				tetr->coord[l].y = y;
				if (l < 3)
					l++;
			}
			x++;
			str++;
		}
		x = 0;
		y++;
		str++;
	}
//	printf("coord[3].x = %d coord[3].y = %d\n", tetr->coord[3].x, tetr->coord[3].y);
}

static	void	printstructs(t_tetr **tetr, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < i)
	{
		ft_putchar(tetr[j]->name);
		ft_putchar('\n');
		while (k <= 3)
		{
			ft_putnbr(tetr[j]->coord[k].x);
			ft_putchar(' ');
			ft_putnbr(tetr[j]->coord[k].y);
			ft_putchar('\n');
			k++;
		}
		k = 0;
		j++;
	}
}

/*
static	void	printstruc(t_tetr test)
{
	int i;

	i = -1;
	ft_putchar(test.name);
	ft_putchar('\n');
	printf("coord[3].x = %d coord[3].y = %d\n", test.coord[3].x, test.coord[3].y);
	while (i <= 3)
	{
		i++;
		ft_putnbr(test.coord[i].x);
		ft_putchar(' ');
		ft_putnbr(test.coord[i].y);
		ft_putchar('\n');
	}
}
*/
static	int		ft_checkconn(char *str)
{
	int			i;
	size_t		count;
	
	i = 0;
	count = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if ((i + 1) <= 20 && str[i + 1] == '#')
				count++;
			if ((i + 5) <= 20 && str[i + 5] == '#')
				count++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				count++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	return ((count == 6 || count == 8) ? 1 : 0);
}

static	int		ft_checksym(char *str)
{
	size_t	i;
	size_t	count;
	size_t	count2;

	i = 0;
	count = 0;
	count2 = 0;
	while (i < 20 && (str[i] == '\n' || str[i] == '#' || str[i] == '.' ))
	{
		if (str[i] == '\n')
			count2++;
		if (str[i] == '#')
			count++;
		i++;
	}
	return ((/*str[i] == '\n' &&*/count2 == 4 && i == 20 && count == 4 && ft_checkconn(str) == 1) ? 1 : 0);
}

static void		ft_read(int fd, t_tetr **tetr, int i)
{
	char	buf[21];
	int		j;

	j = 0;
	while (read(fd, buf, 21) > 0)
	{
		maketetr(buf, tetr[j]);
		if (j > 0)
			printf("WHAT IS GOING ON HERE?\n");
		printf("ARE YOU ALIVE?\n");
		tetr[j]->name = 65 + j;
		j++;
	}
//	printf("coord[3].x = %d coord[3].y = %d\n", tetr[0]->coord[3].x, tetr[0]->coord[3].y);
}

static	int		howmanytetr(int fd)
{
	char	buf[21];
	int		i;

	i = 0;
	while (read(fd, buf, 21) > 0)
	{
		if (ft_checksym(buf) == 1)
			i++;
		else 
			return (-1);

	}
	close(fd);											//?? why does it work like this? idk
	return (i);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		l;
	int		j;
	t_tetr	*tetr;

	if (argc != 2)
		return (0);
	l = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	i = howmanytetr(fd);
	close(fd);											//??
	ft_putstr("How many tetraminos? ");
	ft_putnbr(i);
	ft_putchar('\n');
	if (i < 0)
	{
		ft_putstr("It's not a valid file\n");
		return (0);
	}
	tetr = (t_tetr *)malloc(sizeof(t_tetr) * i);
	fd = open(argv[1], O_RDONLY);
	ft_read(fd, &tetr, i);
//	printf("coord[3].x = %d coord[3].y = %d\n", tetr[j].coord[3].x, tetr[j].coord[3].y);
//	printstruc(tetr[j]);
	printstructs(&tetr, i);
	close(fd);
	return (0);
}
