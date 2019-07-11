/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:59:57 by drdraugr          #+#    #+#             */
/*   Updated: 2019/06/29 21:02:00 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_checker.h"
#include "apply_utils.h"
#include "parser.h"
#include "libft.h"

int			parse_flag(char **arg, t_format *arg_format)
{
	char	*args;

	args = *arg;
	if (is_flag(**arg))
	{
		if (*args == '0' && arg_format->flag[left] == '0')
			arg_format->flag[zero] = '1';
		if (**arg == '-')
		{
			arg_format->flag[left] = '1';
			arg_format->flag[zero] = '0';
		}
		if (**arg == ' ' && arg_format->flag[plus] == '0')
			arg_format->flag[space] = '1';
		if (**arg == '+')
		{
			arg_format->flag[plus] = '1';
			arg_format->flag[space] = '0';
		}
		if (**arg == '#')
			arg_format->flag[spacial] = '1';
		*arg = ++args;
		return (1);
	}
	return (0);
}

int			parse_precision(char **args, va_list ap, t_format *arg_format)
{
	char	*arg;

	arg = *args;
	if (*arg++ == '.')
		if ((arg_format->precision == -1) || (arg_format->precision >= 0))
		{
			arg_format->precision = 0;
			if (*arg == '*')
			{
				arg_format->precision = va_arg(ap, int);
				if (arg_format->precision < 0)
					arg_format->precision = -1;
				*args = ++arg;
				return (1);
			}
			while (1)
				if (accumulate_digit(&arg_format->precision, *arg))
					*args = ++arg;
				else
				{
					*args = arg;
					return (1);
				}
		}
	return (0);
}

int			parse_width(char **args, va_list ap, t_format *arg_format)
{
	char	*arg;

	arg = *args;
	if (*arg != '0')
	{
		if ((ft_isdigit(*arg)) || arg_format->width == -1 || *arg == '*')
			arg_format->width = 0;
		if (*arg == '*' && (*args = ++arg))
		{
			arg_format->width = va_arg(ap, int);
			if (arg_format->width < 0)
			{
				arg_format->width = -arg_format->width;
				arg_format->flag[left] = '1';
			}
			arg_format->flag[zero] = (arg_format->width == 0) ? '1' : '0';
			return ((arg_format->width != 0) ? 1 : 0);
		}
		while (1)
			if (accumulate_digit(&arg_format->width, *arg))
				*args = ++arg;
			else
				break ;
	}
	return ((arg_format->width != 0) ? 1 : 0);
}

int			parse_size(char **args, char *size)
{
	char	*arg;

	arg = *args;
	if (is_size(*arg) && (*size == '\0'))
	{
		*size = *arg;
		*args = ++arg;
		return (1);
	}
	else if (*size == *arg && *size != '\0')
	{
		*size = (*arg == 'h') ? 'H' : 'I';
		*args = ++arg;
		return (1);
	}
	else if (is_size(*arg))
	{
		if (*arg == 'z' || *arg == 'j')
			*size = (*arg == 'z') ? 'z' : 'j';
		else if (*arg == 'l' && (*size == 'h' || *size == 'H'))
			*size = 'l';
		*args = ++arg;
		return (1);
	}
	return (0);
}

int			parse_type(char **args, t_format *arg_format)
{
	char	*arg;

	arg = *args;
	if (is_type(*arg))
	{
		arg_format->type = *arg;
		cast_big_types(arg_format);
		if (arg_format->type == 's' || arg_format->type == 'c')
			arg_format->flag[plus] = '0';
		if (arg_format->type == 'o' || ft_tolower(arg_format->type) == 'x')
		{
			arg_format->flag[plus] = '0';
			arg_format->flag[space] = '0';
		}
		else
			arg_format->flag[spacial] = '0';
		if (arg_format->type == 'p')
			arg_format->flag[spacial] = '1';
		*args = ++arg;
		return (1);
	}
	return (0);
}
