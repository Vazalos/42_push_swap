/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:43:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/20 14:44:25 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new_num)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new_num;
		return ;
	}
	temp = *stack;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new_num;
}


