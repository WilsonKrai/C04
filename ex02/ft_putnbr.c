/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:33:08 by wteles-d          #+#    #+#             */
/*   Updated: 2023/03/21 18:10:22 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_printchar(char a);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		my_printchar('-');
		my_printchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		my_printchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	my_printchar(nb % 10 + '0');
}

void	my_printchar(char a)
{
	write(1, &a, 1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = 0;

	printf("Number:\n");
	scanf("%d", &n);
	ft_putnbr(n);
}
*/
