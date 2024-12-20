/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:43:42 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 16:45:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (nbr < 0)
		{
			write(fd, "-", 1);
			nbr = -nbr;
		}
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
		else
		{
			nbr = nbr + '0';
			write(fd, &nbr, 1);
		}
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(2147483647);
}*/
