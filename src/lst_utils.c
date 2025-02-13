/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:43:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/12 20:10:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_size(t_stack *head)
{
	size_t	n;
	t_stack	*tmp;

	if (!head)
		return (0);
	n = 0;
	tmp = head;
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		n++;
	}
	if (tmp)
		n++;
	return (n);
}

t_stack	*ft_stack_new(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	return (new_node);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	ft_stack_add_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
