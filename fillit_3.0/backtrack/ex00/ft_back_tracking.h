/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_tracking.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BACK_TRACKING_H
# define FT_BACK_TRACKING_H

void	ft_transform(char **argv, int (*res)[9][9]);
void	ft_back_tracking(int table[9][9], int *count, int (*res)[9][9]);
#endif
