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

void	printstructs(t_atetr **mtetr)
{
    int j;
    int k;

    j = 0;
    k = 0;
    while (j < (*mtetr)->count)
    {
        ft_putchar((*mtetr)->tetr[j]->name);
        ft_putchar('\n');
        while (k <= 3)
        {
            ft_putnbr((*mtetr)->tetr[j]->coord[k].x);
            ft_putchar(' ');
            ft_putnbr((*mtetr)->tetr[j]->coord[k].y);
            ft_putchar('\n');
            k++;
        }
        k = 0;
        j++;
    }
}