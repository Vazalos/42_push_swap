/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:50:17 by david-fe          #+#    #+#             */
/*   Updated: 2025/01/23 14:51:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **dest, t_stack **src) //pa is b to a
{
	t_stack	*temp;

	if (*src)
	{
		temp = (*src);
		if ((*src)->next)
		{
			*src = (*src)->next;
			(*src)->prev = NULL;
		}
		else
			*src = NULL;
		if (*dest)
		{
			(*dest)->prev = temp;
			temp->next = (*dest);
			(*dest) = temp;
		}
		else
		{
			*dest = temp;
			temp->next = NULL;
		}
	}
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	ft_printf("pb\n");
}
