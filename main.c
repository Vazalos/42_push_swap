/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:33:57 by david-fe          #+#    #+#             */
/*   Updated: 2024/12/20 11:39:10 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_print_list(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp && temp->next)
	{
		ft_printf("%d", temp->number);
		temp = temp->next;
	}
	if (temp)
		ft_printf("%d", temp->number);
}

t_stack **ft_makelist(char **nlist, int nsize)
{
	int		i;
	t_stack **new_stack;// has to be **?

	i = 1;
	new_stack = NULL;
	*new_stack = ft_stack_new(ft_atoi(nlist[i++]));
	while(i < nsize && nlist[i])
	{
		ft_printf("%s", nlist[i]);
		ft_stack_add_back(new_stack, ft_stack_new(ft_atoi(nlist[i++])));
	}

	return(new_stack);
}

int	main (int argc, char **argv)
{
	t_stack **stack_a;

	if(argc <= 1)
		ft_printf("Error\n"); //only thing that can be printed
	else
	{
		if(ft_parse_args(argc, argv) == 1)
		{
			stack_a = ft_makelist(argv, argc);
			return(ft_printf("valid args"));
		}
		else 
			return(ft_printf("invalid args, try again!"));
	}
}
//I have to use my own printf

//RADIX stack A is 1's & stack B is 0's 
//on check a unit, ten, hundred, etc. 
//you have 3 moves only: RA, PA, PB
// -> 1's are to receive a RA
// -> 0's are to receive a PB
// after all interations on that digit place, PA all in stack B
// repeat while going up from units until the biggest digit place that exists
//after that all is sorted
