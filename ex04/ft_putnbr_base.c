/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:47:10 by wteles-d          #+#    #+#             */
/*   Updated: 2023/03/21 16:11:47 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base_size_and_errors(char *s1)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s1[j] != '\0')
	{
		if (s1[j] == '+' || s1[j] == '-')
			return (1);
		k = j + 1;
		while (s1[k] != '\0')
		{
			if (s1[j] == s1[k])
				return (1);
			k++;
		}
		j++;
	}
	if (j <= 1)
		return (1);
	return (j);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				baselen;
	long			longnbr;

	i = 0;
	longnbr = (long)nbr;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return ;
	if (longnbr == -2147483648)
	{
		my_putchar('-');
		longnbr = 2147483648;
	}
	if (longnbr > baselen)
		ft_putnbr_base(longnbr / baselen, base);
	else if (nbr < 0)
	{
		longnbr = longnbr * (-1);
		my_putchar('-');
		ft_putnbr_base(longnbr / baselen, base);
	}
	my_putchar(base[longnbr % baselen]);
}
/*
#include <stdio.h>

int	main(void)
{
	int	x;
	char	h[100];
	printf("Number: ");
	scanf("%d", &x);
	printf("Base: ");
	scanf("%s", h);
	ft_putnbr_base(x, h);
}
*/
