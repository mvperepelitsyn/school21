/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:38:10 by dfrost-a          #+#    #+#             */
/*   Updated: 2018/11/24 13:05:08 by dfrost-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 != '\0')
		return (*s1);
	if (*s2 != '\0')
		return (-*s2);
	return (0);
}

void	ft_swap(char **s1, char **s2)
{
	char *i;

	i = *s1;
	*s1 = *s2;
	*s2 = i;
}

void	ft_print_params(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int i;
	int k;

	i = 1;
	while (i < argc)
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
				ft_swap(&argv[i], &argv[k]);
			k++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_print_params(argv[i]);
		i++;
	}
	return (0);
}
