/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 05:55:13 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/05 06:11:23 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_create_elem(void *data)
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

int main()
{
    t_list* item = ft_create_elem("asdf");
    printf("%s\n", (char*)item->data);
    printf("%p\n", item->next);
}
