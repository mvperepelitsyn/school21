/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:41:24 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/06/29 20:56:32 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extract.h"
#include "libft.h"
#include "apply_utils.h"

/*
** The function applies precision's format for string and integer number
** It's also apply spacial flag for x, X and o types and plus flag for others
*/

char	*apply_precision(const char *str, t_format *arg_format)
{
	char	*res;
	int		sign;
	int		prefix;
	size_t	len;
	char	type;

	len = ft_strlen(str);
	type = arg_format->type;
	if ((type == 's' || type == 'S') && arg_format->precision < (int)len &&
			arg_format->precision >= 0)
		res = ft_strsub(str, 0, (size_t)arg_format->precision);
	else
	{
		sign = get_sign(str, arg_format);
		prefix = len_hex(str, type, arg_format) * (int)(arg_format->
				flag[spacial] == '1');
		if (arg_format->precision >= (int)len)
			res = ft_strnew_fill((size_t)(arg_format->precision + sign +
					prefix), '0');
		else
			res = ft_strnew_fill(len + sign + prefix, '0');
		ft_strins(res, str, ft_strlen(res) - len, len);
		apply_prefix(arg_format, res, prefix, str);
	}
	return (res);
}

/*
** The function return additional part of string depending of width.
** The part can be empty string or filled by space or zero.
*/

char	*get_extension(const char *str, t_format *arg_format)
{
	char	filler;
	char	*extension;
	size_t	len;

	extension = ft_strnew(1);
	len = (int)ft_strlen(str);
	filler = ' ';
	if (arg_format->width > (int)len)
	{
		if (arg_format->flag[zero] == '1')
			if ((arg_format->precision == -1 && arg_format->type != 'f') || \
				arg_format->type == 'f')
				filler = '0';
		ft_strdel(&extension);
		extension = ft_strnew_fill((size_t)arg_format->width - len, filler);
	}
	return (extension);
}

/*
** The function return formatted string.
*/

char	*apply_format(const char *str, t_format *arg_format)
{
	char *extension;
	char *new_str;
	char *res;

	if (!str)
		return (NULL);
	new_str = (ft_strcmp(str, SNULL) != 0) ?
		apply_precision(str, arg_format) : ft_strdup(str);
	extension = get_extension(new_str, arg_format);
	if (arg_format->flag[left] == '1')
		res = ft_strjoin(new_str, extension);
	else
	{
		new_str[0] = (*str == '-' && *new_str != '-') ? '-' : new_str[0];
		res = ft_strjoin(extension, new_str);
		permutation(res, new_str, arg_format);
	}
	ft_strdel(&new_str);
	ft_strdel(&extension);
	return (res);
}
