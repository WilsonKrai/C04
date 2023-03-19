/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:47:10 by wteles-d          #+#    #+#             */
/*   Updated: 2023/03/19 17:03:03 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
		k = j;
		while (s1[k] != '\0')
		{
			k++;
			if (s1[j] == s1[k])
				return (1);
		}
		j++;
	}
	if (j <= 1)
		return (1);
	return (j);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	baselen;

	i = 0;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return;
	if (nbr > baselen)
		ft_putnbr_base(nbr / baselen, base);
	else if (nbr < 0)
	{
		nbr = nbr * (-1);
		write(1, "-", 1);
		ft_putnbr_base(nbr / baselen, base);
	}
	my_putchar(base[nbr % baselen]);
}

int	main(void)
{
	int	x;
	char	h[100];
	scanf("%d", &x);
	scanf("%s", h);
	ft_putnbr_base(x, h);
}
