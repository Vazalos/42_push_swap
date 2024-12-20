/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:40:01 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/20 16:40:16 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_digitcnt(int to_count)
{
	unsigned int	i;

	i = 0;
	if (to_count == 0)
		return (1);
	if (to_count == -2147483648)
		return (11);
	if (to_count < 0)
		to_count = -to_count;
	while (to_count > 0)
	{
		to_count = to_count / 10;
		i++;
	}
	return (i);
}

unsigned int	ft_putnbr(int nbr)
{
	unsigned int	count;

	count = ft_digitcnt(nbr);
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			count++;
		}
		if (nbr > 9)
		{
			ft_putnbr(nbr / 10);
			ft_putnbr(nbr % 10);
		}
		else
		{
			nbr = nbr + '0';
			write(1, &nbr, 1);
		}
	}
	return (count);
}
/*
int main (void)
{
    int real_return, my_return;

    real_return = printf("%d", -100);
	printf("\n");
    my_return = ft_putnbr(-100);
    printf("\nReal return: %d | My return: %d\n\n", real_return, my_return);
}*/
