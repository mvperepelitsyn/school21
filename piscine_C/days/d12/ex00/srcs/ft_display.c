/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:42:57 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/06 18:22:24 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display(char *nameoffile)
{
	int		f;
	char	charact;

	f = open(nameoffile, O_RDONLY);
	if (f < 0)
		return ;
	while (read(f, &charact, 1))
		write(1, &charact, 1);
	close(f);
}
