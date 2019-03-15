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


static void     printmap(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            ft_putchar(map[i][j]);
            j++;
        }
        ft_putchar(map[i][j]);
        j = 0;
        i++;
    }
}

static void     fillmap(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\n';
        j = 0;
        i++;
    }
    printmap(map);
}

static void     ft_freemap(char **map, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        ft_strdel(&map[j]);
        j++;
    }
    ft_strdel(map);
}

static void     ft_makemap(void)
{
    char    **map;
    int     i;
    int     j;

    j = 0;
    i = 4;
    map = (char **)malloc(sizeof(char *) * i + 1);
    while (j < i)
    {
        map[j] = ft_strnew(i);
        j++;
    }
    map[j] = NULL;
    fillmap(map);
    ft_freemap(map, i);
    /*
    j = 0;
    while (j < 4)
    {
        free(map[j]);
        j++;
    }
    free(map);
     */
}

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
	if (mtetr->count < 0)
	{
		ft_putstr("It's not a valid file\n");
		free(mtetr);
		return (0);
	}
	mtetr->tetr = (t_tetr **)malloc(sizeof(t_tetr) * mtetr->count);
	//fd = open(argv[1], O_RDONLY);
	fd = open(NAME, O_RDONLY);
	ft_read(fd, &mtetr);
    printstructs(&mtetr);
    ft_makemap();
	free(mtetr->tetr);
	free(mtetr);
	close(fd);
	return (0);
}
