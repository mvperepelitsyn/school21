/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:26:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static  void    move_minusx(t_atetr **mtetr, int i)
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

static  void    move_minusy(t_atetr **mtetr, int i)
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

void            move_coord(t_atetr **mtetr, int k)
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