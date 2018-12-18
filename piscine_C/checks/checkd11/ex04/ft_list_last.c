/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:06:16 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 10:24:23 by dfrost-a         ###   ########.fr       */
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


t_list	*ft_list_last(t_list *begin_list)
{
	t_list *element;

	if (!begin_list)
		return (0);
	element = begin_list;
	while (element->next)
		element = element->next;
	return (element);
}

#define CE(data) ft_create_elem(data)
#define CL(list) crap_a_list(list)

void crap_a_list(t_list* list)
{
    for (; list != 0; list = list->next)
        printf("%s,", (char*)list->data);
    printf("\n");
}

int main()
{
    t_list* list = 0;
    printf("%p\n", ft_list_last(list));
    list = CE("asdf");
    printf("%s\n", (char*)(ft_list_last(list)->data));
    list->next = CE("qwer");
    list->next->next = CE("zxcv");
    printf("%s\n", (char*)(ft_list_last(list)->data));
    list = CE("asdf");
    list->next = CE("qwer");
    list->next->next = CE("zxcv");
    list->next->next->next = CE("uiop");
    printf("%s\n", (char*)(ft_list_last(list)->data));
    list->next->next->next->next = CE("hjkl");
    printf("%s\n", (char*)(ft_list_last(list)->data));
}
