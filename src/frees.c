/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:52:34 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/16 12:02:06 by david-fe         ###   ########.fr       */
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
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	stack_a = NULL;
	stack_b = NULL;
	if (is_error == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

void	ft_free_arglist(char **arglist)
{
	int	i;

	i = 0;
	if (arglist)
	{
		while (arglist[i])
		{
			free(arglist[i]);
			i++;
		}
	}
	if (arglist)
		free(arglist);
}
