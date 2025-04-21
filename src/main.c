/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:57 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/17 11:25:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b,
				t_stack *biggest, int argc)
{
	if (argc <= 6)
		ft_sort_few(stack_a, stack_b, biggest);
	else
		ft_radix(stack_a, stack_b, biggest);
}

int	ft_alloc_check(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*biggest;
	int		argnum;

	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (ft_alloc_check(stack_a, stack_b) == 1)
		return (ft_free_and_return(stack_a, stack_b, 1));
	argnum = ft_parse_args(argc, argv, stack_a);
	if (argnum == 0)
		return (ft_free_and_return(stack_a, stack_b, 1));
	biggest = ft_set_index(stack_a);
	if (ft_is_sorted(stack_a) == 1)
		return (ft_free_and_return(stack_a, stack_b, 0));
	ft_sort_algo(stack_a, stack_b, biggest, argnum);
	return (ft_free_and_return(stack_a, stack_b, 0));
}
//	ft_print_lists(stack_a, stack_b); // use before last return
