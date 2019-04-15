/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:32:29 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/10 13:43:38 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_open_tetr(char *argv, t_atetr *mtetr)
{
	int		fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_exit();
	ft_read_tetr(fd, mtetr);
}

void		ft_read_tetr(int fd, t_atetr *mtetr)
{
	char	*buf;
	int		i;
	int		n;
	int		l;

	i = 0;
	l = 0;
	buf = ft_strnew(21);
	while ((n = read(fd, buf, 21)))
	{
		l = n;
		ft_create_tetr(buf, i, mtetr);
		if (((*mtetr).count = i + 1) > 26)
			ft_exit();
		i++;
	}
	ft_strdel(&buf);
	if (n != 0 || l != 20)
		ft_exit();
}
