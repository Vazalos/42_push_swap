/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:11 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/23 17:55:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack *to_rotate;
	t_stack *temp;

	if(*stack && (*stack)->next)
	{
		temp = *stack;
		to_rotate = *stack;
		while (temp && temp->next != NULL)
			temp = temp->next;
		temp->next = to_rotate;
		to_rotate->prev = temp;
		*stack = to_rotate->next;
		(*stack)->prev = NULL;
		to_rotate->next = NULL;
	}
}

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
