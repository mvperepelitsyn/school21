/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:48:09 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 20:51:36 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_UTILS_H
# define APPLY_UTILS_H

# include "format.h"

void	permutation(char *res, const char *new_str, t_format *arg_format);
void	apply_prefix(t_format *arg_format, char *res, int prefix,
		const char *str);
int		get_sign(const char *str, t_format *arg_format);
int		len_hex(const char *str, char type, t_format *arg_format);
void	cast_big_types(t_format *arg_format);

#endif
