/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:56:20 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 20:43:09 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

/*
** flags
** none print normally (right justify, space fill)
** '0'    leading zero fill
** '+'    print plus on positive numbers
** ' '    invisible plus sign
** '-'    left justify
** '#'    spacial
** priority:
** '+' > ' ', '-' > '0'
*/

typedef	enum		e_params
{
	zero,
	plus,
	space,
	left,
	spacial
}					t_params;

typedef struct		s_format
{
	char			flag[5];
	int				width;
	int				precision;
	char			size;
	char			type;
}					t_format;

void				init_format(t_format *arg_format);
int					is_empty(t_format *arg_format);
void				print_format(t_format *arg_format);

#endif
