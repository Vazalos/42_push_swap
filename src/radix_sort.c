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

void	ft_sort_three(t_stack **stack_a, t_stack *biggest)
{
	if(ft_is_sorted(stack_a) == 0)
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
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b, t_stack *biggest,
	int pb_index)
{
	if ((*stack_a)->index == 0 || ((*stack_a)->index == 1 && pb_index == 0))
		pb(stack_b, stack_a);
	else
	{
		if ((*stack_a)->next->next->next->index == 0
			|| ((*stack_a)->next->next->next->index == 1 && pb_index == 0))
			rra(stack_a);
		else
			while (!((*stack_a)->index == 0
					|| ((*stack_a)->index == 1 && pb_index == 0)))
				ra(stack_a);
		if(ft_is_sorted(stack_a) == 0)
			pb(stack_b, stack_a);
	}
	ft_sort_three(stack_a, biggest);
	pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_stack *biggest)
{
	t_stack	*temp;
	int		pb_index;

	if ((*stack_a)->index == 1 || (*stack_a)->index == 0)
	{
		pb_index = (*stack_a)->index;
		pb(stack_b, stack_a);
	}
	else
	{
		temp = (*stack_a)->next->next->next;
		if (temp->index == 1 || temp->next->index == 1
			|| temp->index == 0 || temp->next->index == 0)
			while ((*stack_a)->index != 1 && (*stack_a)->index != 0)
				rra(stack_a);
		else
			while ((*stack_a)->index != 1 && (*stack_a)->index != 0)
				ra(stack_a);
		pb_index = (*stack_a)->index;
		pb(stack_b, stack_a);
	}
	ft_sort_four(stack_a, stack_b, biggest, pb_index);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, t_stack *biggest)
{
	if (biggest->index == 1)
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	if (biggest->index == 2)
		ft_sort_three(stack_a, biggest);
	if (biggest->index == 3)
		ft_sort_four(stack_a, stack_b, biggest, 1);
	if (biggest->index == 4)
		ft_sort_five(stack_a, stack_b, biggest);
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
