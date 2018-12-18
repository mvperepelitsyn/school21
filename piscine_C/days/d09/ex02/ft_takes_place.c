/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:25:01 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/08/30 19:11:21 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *time(int hour, char time[5])
{
	if (hour >= 12 && hour < 24)
		time = "P.M.";
	else
		time = "A.M.";
	return (time);
}

void ft_takes_place(int hour)
{
	char time[5];
	int h;
	int h12;

	if (hour < 0 || hour > 23)
		return ;
	else
	{
		printf("THE FOLLOWING TAKES PLACE BETWEEN ");
		printf("%d.00 %s AND %d.00 %s\n", hour, time(hour, time),\
				(hour + 1), time(hour + 1, time));
	}
}
