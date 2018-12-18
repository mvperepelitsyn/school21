/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:37:08 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 17:23:12 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

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

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*t;
	t_list	*list;
	int		i;

	if (ac <= 0)
		return (NULL);
	i = 0;
	t = NULL;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = t;
		t = list;
		i++;
	}
	return (list);
}

#define CE(data) ft_create_elem(data)
#define CL(list) crap_a_list(list)

void crap_a_list(t_list* list)
{
    for (; list != 0; list = list->next)
        printf("%s,", (char*)list->data);
    printf("\n");
}

int main(int argc, char** argv)
{
    t_list* list = ft_list_push_params(argc, argv);
    CL(list);
}
