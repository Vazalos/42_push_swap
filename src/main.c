/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:57 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/12 20:10:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (*stack)
	{
		while (temp != NULL)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = temp;
		}
	}
	if (stack)
		free(stack);
}

int	ft_free_and_return(t_stack **stack_a, t_stack **stack_b, int is_error)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (is_error == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

void	ft_sort_algo(t_stack **stack_a, t_stack **stack_b, 
				  t_stack *biggest, int argc)
{
	if (argc <= 6)
		ft_sort_few(stack_a, stack_b, biggest);
	else
		ft_radix(stack_a, stack_b, biggest);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*biggest;
	int		argnum;
	char	**argval;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (ft_free_and_return(stack_a, stack_b, 1));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ft_parse_args(argc, argv) == 1)
		stack_a = ft_makelist(argv, argc, stack_a);
	else
		return (ft_free_and_return(stack_a, stack_b, 1));
	biggest = ft_set_index(stack_a);
	if (ft_is_sorted(stack_a) == 1)
		return (ft_free_and_return(stack_a, stack_b, 0));
	ft_sort_algo(stack_a, stack_b, biggest, argc);
	ft_print_lists(stack_a, stack_b); //*						 */DELETE
	return (ft_free_and_return(stack_a, stack_b, 0));
}
//	ft_print_lists(stack_a, stack_b);

//to-do handle 1 and 2-5 numbers, handle PARSING for negatives
//proper NUM check and split

//RADIX stack A is 1's & stack B is 0's 
//on check a unit, ten, hundred, etc. 
//you have 3 moves only: RA, PA, PB
// -> 1's are to receive a RA
// -> 0's are to receive a PB
// after all interations on that digit place, PA all in stack B
// repeat while going up from units until the biggest digit place that exists
//after that all is sorted
