/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:45:47 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/12 20:47:21 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_lists(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_a;
	ft_printf("\na: ");
	while (temp)
	{
		ft_printf("%d(%d) ", temp->value, temp->index);
		temp = temp->next;
	}
	temp = *stack_b;
	ft_printf("\nb: ");
	while (temp)
	{
		ft_printf("%d(%d) ", temp->value, temp->index);
		temp = temp->next;
	}
	ft_printf("\n\n");
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

t_stack	*ft_set_index(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*smallest;
	t_stack	*biggest;
	static int		index;

	smallest = NULL;
	while (1)
	{
		temp = *stack;
		if (smallest)
			biggest = smallest;
		smallest = NULL;
		while (temp)
		{
			if (temp->index == -1 && !smallest)
				smallest = temp;
			//else if (temp->value == smallest->value)
			//	return(NULL);
			else if (temp->index == -1 && temp->value < smallest->value)
				smallest = temp;
			temp = temp->next;
		}
		if (!smallest)
			return (biggest);
		smallest->index = index++;
	}
}

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

int	ft_max_bits(t_stack *biggest)
{
	int	max_bits;
	int	temp;

	max_bits = 0;
	temp = biggest->index;
	if (temp == 0)
		return (1);
	while (temp > 0)
	{
		(temp) >>= 1;
		max_bits++;
	}
	return (max_bits);
}
