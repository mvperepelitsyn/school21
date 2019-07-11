/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drdraugr <variya1@yandex.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:07:01 by drdraugr          #+#    #+#             */
/*   Updated: 2018/12/19 18:51:32 by drdraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*new;
	t_list	*tmp;

	res = NULL;
	while (lst)
	{
		tmp = f(lst);
		new = ft_lstnew(tmp->content, tmp->content_size);
		if (new == NULL)
		{
			while (res)
			{
				free(res->content);
				free((size_t *)res->content_size);
				res = res->next;
			}
			free(res);
			return (NULL);
		}
		ft_lstappend(&res, new);
		lst = lst->next;
	}
	return (res);
}
