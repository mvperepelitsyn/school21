/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 06:21:47 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 07:32:45 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list        *ft_create_elem(void *data)
{
    t_list *element;
    
    element = (t_list*)malloc(sizeof(t_list));
    if (element)
    {
        element->data = data;
        element->next = NULL;
    }
    return (element);
}


void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *elem;

	if (begin_list && *begin_list)
	{
        elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
	else
        *begin_list = ft_create_elem(data);
}

void crap_a_list(t_list* list)
{
    for (; list != 0; list = list->next)
        printf("%s,", (char*)list->data);
    printf("\n");
}

int main()
{
    t_list* list = 0;
    ft_list_push_back(&list, "asdf");
    crap_a_list(list);
    ft_list_push_back(&list, "qwer");
    ft_list_push_back(&list, "zxcv");
    crap_a_list(list);
    list = 0;
    ft_list_push_back(&list, "uiop");
    ft_list_push_back(&list, "hjkl");
    crap_a_list(list);
}
