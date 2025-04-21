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

int	ft_arg_count(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
		i++;
	return (i);
}

char	**ft_arg_split(int argc, char **argv)
{
	char	**arglist;

	arglist = ft_split(argv[1], ' ');
	return (arglist);
}

int	ft_is_arg_duplicated(int argc, char **argv, int s)
{
	int	i;
	int	j;
	int	k;

	i = s;
	j = 0;
	while (i < argc && argv[i])
	{
		k = i + 1;
		while (argv[k])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[k])
				|| ft_strlen(argv[i]) == 0 || ft_strlen(argv[k]) == 0)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_digitchr(int argc, char **argv, int s)
{
	int	i;
	int	j;

	i = s;
	j = 0;
	while (i < argc && argv[i])
	{
		while (argv[i][j])
		{
			if (ft_strchr("1234567890-+", argv[i][j]) == NULL)
				return (0);
			else if (!((ft_isdigit(argv[i][j]) == 1 && argv[i][j]) ||
				(j == 0 && (argv[i][j] == '+' || argv[i][j] == '-') &&
				(argv[i][j + 1]) && (ft_isdigit(argv[i][j + 1]) == 1))))
				return (0);
			else if (ft_atol(argv[i]) > MAX || ft_atol(argv[i]) < MIN)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	if (ft_is_arg_duplicated(argc, argv, s) == 0)
		return (0);
	return (1);
}
/*
void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		ft_printf("Element %d: %s\n", i, split[i]);
		i++;
	}
}
*/

int	ft_parse_args(int argc, char **argv, t_stack **stack_a)
{
	char	**arglist;
	int		argcount;

	arglist = NULL;
	if (argc == 2)
	{
		arglist = ft_arg_split(argc, argv);
		if (arglist == NULL)
			return (0);
		argcount = ft_arg_count(arglist);
		if (ft_digitchr(argcount, arglist, 0) == 0)
			return (ft_free_arglist(arglist), 0);
		stack_a = ft_makelist(arglist, argcount, stack_a, 0);
		ft_free_arglist(arglist);
		return (argcount);
	}
	else if (argc > 2)
	{
		if (ft_digitchr(argc, argv, 1) == 0)
			return (0);
		stack_a = ft_makelist(argv, argc, stack_a, 1);
		return (argc - 1);
	}
	else
		return (0);
}
