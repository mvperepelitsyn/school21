/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 18:30:50 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 21:13:46 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "extract.h"
#include <stddef.h>
#include <stdint.h>

char		*extract_str(t_format *arg_format, va_list ap)
{
	char	*str;
	char	*ap_str;

	str = NULL;
	ap_str = NULL;
	if (arg_format->size == 'l')
	{
		ap_str = (str_to_utf(va_arg(ap, unsigned int *)));
		str = ft_strdup(ap_str);
		ft_strdel(&ap_str);
	}
	else
		str = ft_strdup(va_arg(ap, char *));
	return (str);
}

static char	*get_null(t_format *arg_format)
{
	char *res;

	res = ft_memalloc(ft_strlen(SNULL) + 1);
	ft_strncpy(res, SNULL, ft_strlen(SNULL));
	arg_format->flag[zero] = '0';
	return (res);
}

char		*extract_string(t_format *arg_format, va_list ap)
{
	char	*str;

	str = NULL;
	if (arg_format->type == 'c')
		str = extract_symbol(arg_format, ap);
	if (arg_format->type == 's')
		str = extract_str(arg_format, ap);
	if (str == NULL && arg_format->type == 's')
	{
		ft_strdel(&str);
		str = get_null(arg_format);
	}
	if (str != NULL)
		arg_format->precision = ((arg_format->type == 'c' || arg_format->type ==
			's') && (*str == '\0' || arg_format->precision >=
					(int)ft_strlen(str))) ? -1 : arg_format->precision;
	return (str);
}
