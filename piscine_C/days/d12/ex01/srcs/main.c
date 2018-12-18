/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:17:13 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/06 23:31:13 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_include.h"

int		main(int argc, char *argv[])
{
	if (argc == 1)
		ft_write();
	else
		ft_display(argc, argv);
	return (0);
}
