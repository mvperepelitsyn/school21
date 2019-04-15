/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:58:21 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/04/11 19:49:49 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_atetr *mtetr;

	if (argc == 2)
	{
		if (!(mtetr = (t_atetr *)malloc(sizeof(t_atetr))))
			ft_exit();
		ft_open_tetr(argv[1], mtetr);
		ft_algo(mtetr);
		ft_print_map(mtetr->map);
		exit(0);
	}
	else
	{
		ft_putendl("usage: ./fillit	input_file");
		exit(0);
	}
}
