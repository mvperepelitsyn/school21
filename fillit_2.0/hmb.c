/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:47:02 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/02/27 21:58:34 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int         checkconnections(char *c)
{
    int			i;
    size_t      count;
    
    i = 0;
	count = 0;
    while (i < 21)
    {
        if (c[i] == '#')
        {
            if ((i + 1) <= 20 && c[i + 1] == '#')
                count++;
            if ((i + 5) <= 20 && c[i + 5] == '#')
                count++;
            if ((i - 1) >= 0 && c[i - 1] == '#')
                count++;
            if ((i - 5) >= 0 && c[i - 5] == '#')
                count++;
        }
//		printf("count = %zu\n", count);
        i++;
    }
//    return ((count == 6 || count == 8) ? 0 : -1);
	return (count);
}
int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	buf[25];
	int 	x;
	int		y;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	x = read(fd, buf, 25);
	y = checkconnections(buf);
	printf("Hmb =  %d\nHmcon = %d\n", x, y);
	return (0);
}
