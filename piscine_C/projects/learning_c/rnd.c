/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:27:25 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/09 14:35:52 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		main(void)
{
	srand(time(NULL));
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
	printf("%d\n", rand() % 20);
}
