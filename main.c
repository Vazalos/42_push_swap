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

void	ft_print_list(t_stack **lst, char name)
{
	t_stack	*temp;

	temp = *lst;
	ft_printf("%c ", name);
	while (temp && temp->next)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	if (temp)
		ft_printf("%d\n", temp->value);
}

t_stack **ft_makelist(char **nlist, int nsize, t_stack **stack_a)
{
	int		i;
	t_stack *current;

	i = 1;
	current = NULL;
	while(i < nsize && nlist[i])
	{
		current = ft_stack_new(ft_atoi(nlist[i++]));
		ft_stack_add_back(stack_a, current);
	}
	return(stack_a);
}

int	main (int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));

	if(argc <= 1)
		ft_printf("Error\n"); //only error message that can be printed
	else
	{
		if(ft_parse_args(argc, argv) == 1)
			stack_a = ft_makelist(argv, argc, stack_a);
		else 
			ft_printf("Error\n"); //only error message that can be printed
	}
	ft_print_list(stack_a, 'a');
	ft_print_list(stack_b, 'b');
	printf("\n");
	sa(stack_a);
	ft_print_list(stack_a, 'a');
	ft_print_list(stack_b, 'b');
	printf("\n");
	pb(stack_b, stack_a);
	ft_print_list(stack_a, 'a');
	ft_print_list(stack_b, 'b');
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
