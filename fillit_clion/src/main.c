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


static void     printmap(char **map, int l)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < l)
    {
        while (j < l)
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
    //printmap(map);
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

static char     **ft_makemap(int i)
{
    char    **map;
    int     j;

    j = 0;
    map = (char **)malloc(sizeof(char *) * i + 1);
    while (j < i)
    {
        map[j] = ft_strnew(i);
        j++;
    }
    map[j] = NULL;
    fillmap(map);
    return(map);
    //ft_freemap(map, i);
}

static void     move_minusx(t_atetr **mtetr, int i)
{
    int l;

    l = 0;
    while (l < 4)
    {
        (*mtetr)->tetr[i]->coord[l].x++;
        if ((*mtetr)->tetr[i]->coord[l].x < 0)
            move_minusx(mtetr, i);
        l++;
    }
}

static void     move_minusy(t_atetr **mtetr, int i)
{
    int l;

    l = 0;
    while (l < 4)
    {
        (*mtetr)->tetr[i]->coord[l].y++;
        if ((*mtetr)->tetr[i]->coord[l].y < 0)
            move_minusy(mtetr, i);
        l++;
    }
}

static  void    move_coord(t_atetr **mtetr, int k)
{
    int i;
    int x;
    int y;
    int l;

    i = 0;
    l = 0;
    while (i < k)
    {
        x = (*mtetr)->tetr[i]->coord[0].x;
        y = (*mtetr)->tetr[i]->coord[0].y;
        while (l < 4)
        {
            (*mtetr)->tetr[i]->coord[l].x = (*mtetr)->tetr[i]->coord[l].x - x;
            (*mtetr)->tetr[i]->coord[l].y = (*mtetr)->tetr[i]->coord[l].y - y;
            if ((*mtetr)->tetr[i]->coord[l].x < 0)
                move_minusx(mtetr, i);
            if ((*mtetr)->tetr[i]->coord[l].y < 0)
                move_minusy(mtetr, i);
            l++;

        }
        l = 0;
        i++;
    }
}

static  void    ft_solve(t_atetr **mtetr)
{
    int     i;
    char    **map;

    i = 4;
    map = ft_makemap(i);

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
	if (mtetr->count < 0 || mtetr->count > 26)
	{
		ft_putstr("error\n");
		free(mtetr);
		return (0);
	}
	mtetr->tetr = (t_tetr **)malloc(sizeof(t_tetr) * mtetr->count);
	//fd = open(argv[1], O_RDONLY);
	fd = open(NAME, O_RDONLY);
	ft_read(fd, &mtetr);
	move_coord(&mtetr, mtetr->count);
    printstructs(&mtetr);
    //ft_solve(&mtetr);
	free(mtetr->tetr);
	free(mtetr);
	close(fd);
	return (0);
}
