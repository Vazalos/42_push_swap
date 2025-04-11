/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:54:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/12 20:10:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

int	ft_arg_split(int argc, char **argv)
{
	int		i;
	char	**arglist;

	i = 0;
	arglist = NULL;
	if (ft_strchr(argv[1], ' ') && argc == 2)
		arglist = ft_split(argv[1], ' ');
	return (1);
}

int	ft_digitchr(int argc, char **argv) // handle args like "2 2" 2
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i < argc && argv[i])
	{
		if ((ft_isdigit(argv[i][++j]) == 1 && argv[i][j]) ||
			(j == 0 && (argv[i][j] == '+' || argv[i][j] == '-')))
		{
			if (j > 11 || ft_atol(argv[i]) > INT_MAX
				|| ft_atol(argv[i]) < INT_MIN)
				return (0);
		}
		else
		{
			return (0);
		}
		j = -1;
	}
	return (1);
}

int	ft_parse_args(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (ft_arg_split(argc, argv) == 0)
		return (0);
	if (ft_digitchr(argc, argv) == 0)
		return (0);
	return (1);
}
