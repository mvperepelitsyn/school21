/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:43:12 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/06 18:37:40 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft_include.h"

int		main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc == 2)
		ft_display(argv[1]);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	return (0);
}
