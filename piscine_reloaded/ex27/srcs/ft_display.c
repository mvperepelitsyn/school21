/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:04:33 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/24 12:38:51 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display(char *nameoffile)
{
	int		i;
	char	ch;

	i = open(nameoffile, O_RDONLY);
	if (i < 0)
		return ;
	while (read(i, &ch, 1))
		write(1, &ch, 1);
	close(i);
}
