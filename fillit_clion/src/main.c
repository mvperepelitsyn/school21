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

static void     fillmap(char **map, int k)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < k)
    {
        while (j < k)
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
    fillmap(map, i);
    return(map);
    //ft_freemap(map, i);
}

static  int     ft_fit(int  k,  t_atetr **mtetr)
{
    int i;
    int maxx;
    int maxy;
    int l;

    i = 0;
    l = 0;
    maxx = (*mtetr)->tetr[i]->coord[l].x;
    maxy = (*mtetr)->tetr[i]->coord[l].y;
    while (i < (*mtetr)->count)
    {
        while (l < 4)
        {
            if ((*mtetr)->tetr[i]->coord[l].x > maxx)
                maxx = (*mtetr)->tetr[i]->coord[l].x;
            if ((*mtetr)->tetr[i]->coord[l].y > maxy)
                maxy = (*mtetr)->tetr[i]->coord[l].y;
            l++;
        }
        l = 0;
        i++;
    }
    return ((maxx > (k - 1) || maxy > (k - 1)) ? 0 : 1);
}
/*
static  int     doesitfit(char **map, t_atetr **mtetr, int i)
{
    int l;

    l = 0;
    while (l < 4)
    {
        map[(*mtetr)->tetr[i]->coord[l].x)][(*mtetr)->tetr[i]->coord[l].y)] = (*mtetr)->tetr[i]->name;
        l++;
    }
    while (map[i] != NULL)
    {
        while (map[i][j] != '\n')
        {
            map[i][j] =
        }
    }
}
*/

static  void    ft_fillmap(char **map, t_atetr **mtetr)
{
    int l;
    int j;

    l = 0;
    j = 0;
    while (l < 4)
    {
        map[(*mtetr)->tetr[j]->coord[l].y][(*mtetr)->tetr[j]->coord[l].x] = (*mtetr)->tetr[j]->name;
        l++;
    }


}

static  void    ft_givememap(t_atetr **mtetr)
{
    int     i;
    char    **map;

    i = 0;
    map = ft_makemap(i);
    while (!(ft_fit(i, mtetr)))
    {
        ft_freemap(map, i);
        i++;
        map = ft_makemap(i);
    }
    ft_fillmap(map, mtetr);
    printmap(map, i);
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
	if (mtetr->count < 1 || mtetr->count > 26)
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
    ft_givememap(&mtetr);
	free(mtetr->tetr);
	free(mtetr);
	close(fd);
	return (0);
}
