/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 07:51:20 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 09:28:03 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

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


void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *element;

	element = ft_create_elem(data);
	element->next = *begin_list;
	*begin_list = element;
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
    ft_list_push_front(&list, "asdf");
    crap_a_list(list);
    ft_list_push_front(&list, "qwer");
    ft_list_push_front(&list, "zxcv");
    crap_a_list(list);
    list = 0;
    ft_list_push_front(&list, "uiop");
    ft_list_push_front(&list, "hjkl");
    crap_a_list(list);
}
