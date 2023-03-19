/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:33:08 by wteles-d          #+#    #+#             */
/*   Updated: 2023/03/16 16:35:12 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printchar(char a);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		printchar('-');
		printchar('2');
		nb = 147483648;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	else if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
		ft_putnbr(nb / 10);
	}
	printchar(nb % 10 + '0');
}

void	printchar(char a)
{
	write(1, &a, 1);
}
/*
int	main(void)
{
	ft_putnbr(-24482);
}
*/
