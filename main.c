/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:57 by david-fe          #+#    #+#             */
/*   Updated: 2024/12/20 11:39:10 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_index(t_stack **stack)
{
	t_stack *temp;
	t_stack *smallest;
	int	biggest;
	int	index;

	index = 0;
	smallest = NULL;
	while (1)
	{
		temp = *stack;
		if(smallest)
			biggest = smallest->value;
		smallest = NULL;
		while (temp)
		{
			if (temp->index == -1 && !smallest)
				smallest = temp;
			else if (temp->index == -1 && temp->value < smallest->value)
				smallest = temp;
			temp = temp->next;
		}
		if(!smallest)
			return(biggest);
		smallest->index = index++;
	}
}

t_stack	**ft_makelist(char **nlist, int nsize, t_stack **stack_a)
{
	int		i;
	t_stack	*current;

	i = 1;
	current = NULL;
	while (i < nsize && nlist[i])
	{
		current = ft_stack_new(ft_atoi(nlist[i++]));
		ft_stack_add_back(stack_a, current);
	}
	return (stack_a);
}

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
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ft_parse_args(argc, argv) == 1)
	{
		stack_a = ft_makelist(argv, argc, stack_a);
	}
	else
	{
		ft_printf("Error\n");
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_printf("%d\n\n", ft_set_index(stack_a));

	//
	ft_print_lists(stack_a, stack_b);
	rra(stack_a);
	ft_print_lists(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
//to-do BIT SHIFTING, RADIX ALGO, PARSING, ERROR messages

//RADIX stack A is 1's & stack B is 0's 
//on check a unit, ten, hundred, etc. 
//you have 3 moves only: RA, PA, PB
// -> 1's are to receive a RA
// -> 0's are to receive a PB
// after all interations on that digit place, PA all in stack B
// repeat while going up from units until the biggest digit place that exists
//after that all is sorted
