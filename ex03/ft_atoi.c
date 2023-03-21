/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:08 by wteles-d          #+#    #+#             */
/*   Updated: 2023/03/21 15:13:54 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_neg(char *sn)
{
	int	h;
	int	j;

	h = 1;
	j = 0;
	while (sn[j] != '\0' && (!(sn[j] <= 58 && sn[j] >= 47)))
	{
		if (sn[j] == '-')
			h = -h;
		j++;
	}
	return (h);
}

int	check_ws(char *s1)
{
	int	x;
	int	save;

	x = 0;
	save = 0;
	while (s1[x] != '\0')
	{
		if (s1[x] == '\f' || s1[x] == '\n'
			|| s1[x] == '\r' || s1[x] == '\t'
			|| s1[x] == '\v' || s1[x] == ' ')
			save++;
		x++;
	}
	return (save);
}

int	ft_atoi(char *str)
{
	int	i;
	int	total;

	total = 0;
	i = check_ws(str);
	while (str[i] != '\0')
	{
		if ((!(str[i] <= 58 && str[i] >= 47))
			&& str[i] != '-' && str[i] != '+')
			break ;
		else
			if (str[i] <= 58 && str[i] >= 47)
				total = total * 10 + (str[i] - '0');
		i++;
	}
	total = total * find_neg(str);
	return (total);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{	
	char	t1[100];
	printf("Input string: ");
	scanf("%s", t1);
	printf("%d\n", ft_atoi(t1));
	printf("%d\n", atoi(t1));
}
*/
