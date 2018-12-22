/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:14:16 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/12/22 16:27:53 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(const int fd, char **line);
#endif
