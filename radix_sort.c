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

#include "push_swap.h"

int	ft_radix_check(void)
{
return(1);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b, int biggest)
{
	int			bit_pos;
	int			to_compare;
	t_stack		*temp;

	bit_pos = 0;
	temp = *stack_a;
	while()
	{
		while (temp)
		{
			if()
				ra(stack_a);
			else 
				pb(stack_b, stack_a);
			temp = temp->next;
		}
	}
}

//to-do BIT SHIFTING, RADIX ALGO, PARSING, ERROR messages

//RADIX stack A is 1's & stack B is 0's 
//on check a unit, ten, hundred, etc. 
//you have 3 moves only: RA, PA, PB
// -> 1's are to receive a RA
// -> 0's are to receive a PB
// after all interations on that digit place, PA all in stack B
// repeat while going up from units until the biggest digit place that exists
//after that all is sorted
