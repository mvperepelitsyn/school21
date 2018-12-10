/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:57:27 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/24 12:39:16 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft_include.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc == 2)
		ft_display(argv[1]);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	return (0);
}
