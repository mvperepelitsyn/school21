/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:38:33 by dfrost-a          #+#    #+#             */
/*   Updated: 2019/02/20 14:11:29 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(char **str, int fd)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	tmp = ft_strjoin(*str, buf);
	ft_strdel(&(*str));
	*str = tmp;
	return (ret);
}

static int	ft_getl(char **str, char **line, char *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	tmp2 = ft_strnew(0);
	*line = ft_strjoin(tmp2, *str);
	if (i == 0 && ft_strlen(*str) != 0)
	{
		ft_strdel(&(*str));
		*str = ft_strnew(0);
		return (1);
	}
	if (i == 0 && !(ft_strlen(*str)))
	{
		return (0);
	}
	tmp = *str;
	*str = ft_strjoin(s + 1, tmp2);
	ft_strdel(&tmp2);
	ft_strdel(&tmp);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*s;
	static char	*str;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	ret = BUFF_SIZE;
	while (line)
	{
		s = str;
		while (*s || ret < BUFF_SIZE)
		{
			if (*s == '\n' || *s == '\0')
				return (ft_getl(&str, line, s));
			s++;
		}
		ret = ft_read(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
