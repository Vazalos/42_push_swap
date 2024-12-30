/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:54:10 by david-fe          #+#    #+#             */
/*   Updated: 2024/12/23 15:54:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while(++i < argc && argv[i])
	{
		ft_printf("check 1: argc %d, argv[%d]\n", argc, i);
		if(ft_isdigit(argv[i][++j]) == 1 && argv[i][j])		
		{
			ft_printf("check 2\n");
			ft_printf("%d\n", ft_atoi(argv[i]));
		}
		else
			return(0);
	}
	return(1);
}

