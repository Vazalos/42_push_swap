/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:44:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/04 11:54:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
		(temp)>>=1;
		max_bits++;
	}
	return (max_bits);
}

int	ft_is_sorted(t_stack **stack_a)
{
	t_stack *temp;

	temp = *stack_a;
	while(temp && temp->next)
	{
		if(temp->value > temp->next->value)
			return(0);
		temp = temp->next;
	}
	return(1);
}

void	ft_sort_three(t_stack **stack_a, t_stack *biggest)
{
	t_stack *temp;

	temp = *stack_a;
	if (temp->prev->index == biggest->index)// ABC and BAC done
		sa(stack_a);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b, t_stack *biggest)
{
	int			bit_pos;
	int			max_bits;
	int			node_count;
	t_stack		*temp;

	max_bits = ft_max_bits(biggest);	
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		node_count = (biggest->index);
		while(node_count >= 0)
		{
			temp = *stack_a;
			if((temp->index >> bit_pos) & 1)
				ra(stack_a);
			else 
				pb(stack_b, stack_a);
			node_count--;
		}
		temp = *stack_b;
		while(temp)
		{
			pa(stack_a, stack_b);
			temp = *stack_b;
		}
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
