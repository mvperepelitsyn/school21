/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:07:55 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 21:07:56 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "parser.h"
#include "extract.h"
#include "ft_printf.h"
#include "format_checker.h"

/*
** The function parse format.
*/

int		parse(char **arg, t_format *arg_format, va_list ap)
{
	char	*c;

	c = (*arg) + 1;
	init_format(arg_format);
	while (*c && is_valid(*c))
	{
		parse_flag(&c, arg_format);
		parse_precision(&c, ap, arg_format);
		parse_width(&c, ap, arg_format);
		parse_size(&c, &arg_format->size);
		if (parse_type(&c, arg_format))
			break ;
	}
	*arg = c;
	if (arg_format->type != '\0')
		return (1);
	return (0);
}

/*
** Print string and return its length;
** (*exctractors)[] is a array of functions witch extract string and apply flags
*/

int		print(t_format *arg_format, va_list ap, int *res)
{
	char	*(*extractors[NUM_EXCTRACTOR])(t_format *, va_list);
	char	*str;
	char	*new_str;
	int		i;

	str = NULL;
	i = -1;
	extractors[0] = extract_number;
	extractors[1] = extract_float;
	extractors[2] = extract_string;
	while (++i < NUM_EXCTRACTOR && str == NULL)
	{
		str = (*extractors[i])(arg_format, ap);
		new_str = (str && *str == '\0' && arg_format->type == 'c') ? \
		apply_format("@", arg_format) : apply_format(str, arg_format);
	}
	if (str == NULL)
		return (0);
	(*str == '\0' && arg_format->type == 'c') ?
	ft_putstr_replace(new_str, '@', '\0') : ft_putstr(new_str);
	ft_strdel(&str);
	*res += (int)(ft_strlen(new_str));
	ft_strdel(&new_str);
	return (1);
}

/*
** Emulate undefined behavior printf function on MAC
*/

int		undefined_print(t_format *arg_format, char **c, int *res)
{
	char	*str;
	char	*new_str;
	char	*s;

	if (!is_empty(arg_format) && arg_format->type == '\0')
	{
		s = *c;
		arg_format->type = 'c';
		str = ft_strnew(1);
		str[0] = **c;
		new_str = apply_format(str, arg_format);
		ft_putstr(new_str);
		*res += ft_strlen(new_str);
		ft_strdel(&new_str);
		ft_strdel(&str);
		if (c && **c)
			*c = ++s;
		return (1);
	}
	return (0);
}

/*
** Emulate standard printf function;
*/

int		ft_printf(const char *format, ...)
{
	t_format	arg_format;
	va_list		ap;
	char		*c;
	int			res;

	va_start(ap, format);
	c = (char *)format;
	res = 0;
	while (*c && ft_strcmp(c, "%") != 0)
	{
		if ((*c == '%') && (*(c + 1) != '%') && parse(&c, &arg_format, ap) &&
		print(&arg_format, ap, &res))
			continue ;
		else if (!undefined_print(&arg_format, &c, &res))
		{
			c = (*(c + 1) == '%' && *c == '%') ? c + 1 : c;
			ft_putchar(*c++);
			res++;
		}
	}
	va_end(ap);
	return (res);
}
