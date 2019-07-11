/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 21:02:22 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/29 21:02:26 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include "format.h"

int	parse(char **args, t_format *arg_format, va_list ap);
int	parse_flag(char **arg, t_format *arg_format);
int	parse_precision(char **args, va_list ap, t_format *arg_format);
int	parse_width(char **args, va_list ap, t_format *arg_format);
int	parse_size(char **args, char *size);
int parse_type(char **args, t_format *arg_format);

#endif
