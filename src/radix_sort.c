/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:44:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/12 20:10:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort_three(t_stack **stack_a, t_stack *biggest)
{
	if (biggest->index == (*stack_a)->next->next->index)
		sa(stack_a);
	else
	{
		if (biggest->index == (*stack_a)->index)
		{
			ra(stack_a);
			if ((*stack_a)->index > (*stack_a)->next->index)
				sa(stack_a);
		}
		else
		{
			if (biggest->index == (*stack_a)->next->index)
			{
				rra(stack_a);
				if ((*stack_a)->index > (*stack_a)->next->index)
					sa(stack_a);
			}
		}
	}
}

void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, t_stack *biggest)
{
	(void)stack_b;
	if (biggest->index == 2)
	{
		ft_sort_three(stack_a, biggest);
	}
	if (biggest->index == 3)
		ft_printf("4 elements");
	if (biggest->index == 4)
		ft_printf("5 elements");
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b, t_stack *biggest)
{
	int			bit_pos;
	int			max_bits;
	int			node_count;

	max_bits = ft_max_bits(biggest);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		node_count = (biggest->index);
		while (node_count >= 0)
		{
			if (((*stack_a)->index >> bit_pos) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
			node_count--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit_pos++;
	}
}

//to-do BIT SHIFTING, RADIX ALGO, PARSING, ERROR messages

//RADIX stack A is 1's & stack B is 0's 
//on check a unit, ten, hundred, etc. 
//you have 3 moves only: RA, PA, PB
// -> 1's are to receive a RA
// -> 0's are to receive a PB
// after all iterations on that digit place, PA all in stack B
// repeat while going up from units until the biggest digit place that exists
//after that all is sorted
