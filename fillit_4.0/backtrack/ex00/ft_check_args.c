/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:21:00 by jschmele          #+#    #+#             */
/*   Updated: 2018/09/02 20:21:42 by jschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int		ft_correct_row(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((s[i] < '1' || s[i] > '9') && s[i] != '.')
			return (0);
	return (1);
}

int		ft_check_inside(char **argv)
{
	int	i;

	i = 0;
	while (++i < 10)
		if (ft_strlen(argv[i]) != 9 || !ft_correct_row(argv[i]))
			return (0);
	return (1);
}

int		ft_check_args(int argc, char **argv)
{
	if (argc != 10)
		return (0);
	return (ft_check_inside(argv));
}
