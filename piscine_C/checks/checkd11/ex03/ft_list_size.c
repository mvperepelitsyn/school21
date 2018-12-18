/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:51:06 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 09:59:07 by dfrost-a         ###   ########.fr       */
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

int	ft_list_size(t_list *begin_list)
{
	int size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

#define CE(data) ft_create_elem(data)

void crap_a_list(t_list* list)
{
    for (; list != 0; list = list->next)
        printf("%s,", (char*)list->data);
    printf("\n");
}

int main()
{
    t_list* list = 0;
    printf("%d\n", ft_list_size(list));
    list = CE("asdf");
    printf("%d\n", ft_list_size(list));
    list->next = CE("qwer");
    list->next->next = CE("zxcv");
    printf("%d\n", ft_list_size(list));
    list = CE("asdf");
    list->next = CE("asdf");
    list->next->next = CE("asdf");
    list->next->next->next = CE("asdf");
    printf("%d\n", ft_list_size(list));
    list->next->next->next->next = CE("asdf");
    printf("%d\n", ft_list_size(list));
}
