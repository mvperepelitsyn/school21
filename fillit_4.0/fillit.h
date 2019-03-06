/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:26:43 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/03/06 12:53:25 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef struct		s_tetr
{
	char		name;
	t_point		coord[3];
}					t_tetr;

#endif
