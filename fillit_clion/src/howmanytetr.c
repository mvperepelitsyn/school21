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

int		howmanytetr(int fd)
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
    close(fd);
    return (i);
}
