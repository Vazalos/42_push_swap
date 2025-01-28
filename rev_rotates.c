/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:24:24 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/28 13:24:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*to_rotate;
	t_stack	*temp;

	if (*stack && (*stack)->next)
	{
		to_rotate = *stack;
		while (to_rotate && to_rotate->next != NULL)
			to_rotate = to_rotate->next;
		temp = to_rotate->prev;
		(*stack)->prev = to_rotate;
		to_rotate->next = (*stack);
		*stack = to_rotate;
		(*stack)->prev = NULL;
		temp->next = NULL;
	}
}

void	rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
