/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:15:51 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/16 15:27:02 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_lstfold(t_list *lst, int (*f)(int, int))
{
	t_list	*list;
	int		res;

	list = lst;
	res = *(int *)(list->content);
	list = list->next;
	while (list)
	{
		res = (*f)(res, *(int *)(list->content));
		list = list->next;
	}
	return (res);
}
