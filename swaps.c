/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:40:25 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/22 16:45:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
}

void	sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
