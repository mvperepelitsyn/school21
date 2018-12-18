/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:22:57 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/09/09 12:32:15 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int		main(void)
{
	double alpha;
	double sin_a;
	double pi;
   
	pi = 3.1415926;
	printf("Vvedite ugol alpha ");	
	scanf("%lf", &alpha);
	alpha = alpha * pi / 180;
	sin_a = sin(alpha);
	printf("sin(alpha) =  %.2lf\n", sin_a);
	return (0);
}
