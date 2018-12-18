/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:13:25 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/06 23:32:46 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../includes/ft_include.h"
#include <stdio.h>

#define BUF_SIZE 4096

void	ft_display(int x, char *elems[])
{
	int		f;
	int		i;
	char	*name;
	char	buf[BUF_SIZE + 1];
	int 	ret;

	i = 0;
	while (x > ++i)
	{
		name = elems[i];
		f = open(name, O_RDWR);
		if (f < 0)
		{
			write(2, "cat: ", 5);
			write(2, name, ft_strlen(name));
			if (errno == 21)
				write(2, ": Is a directory\n", 17);
			else
				write(2, ": No such file or directory\n", 28);
		}
		else
		{
			while ((ret = read(f, &buf, BUF_SIZE)) && ret != -1)
		{
			buf[ret] = '\0';
			write(1, buf, ret);
		}
		}
		close(f);
	}
}
