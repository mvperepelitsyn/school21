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

void		maketetr(char *str, t_atetr **mtetr, int j)
{
    size_t	x;
    size_t	y;
    size_t	l;

    x = 0;
    y = 0;
    l = 0;

    if (((*mtetr)->tetr[j] = (t_tetr *)malloc(sizeof(t_tetr))) == NULL)
        return ;
    while (*str)
    {
        while (*str != '\n')
        {
            if (*str == '#')
            {
                (*mtetr)->tetr[j]->coord[l].x = x;
                (*mtetr)->tetr[j]->coord[l].y = y;
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
}