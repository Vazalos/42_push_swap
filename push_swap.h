/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:30:41 by david-fe          #+#    #+#             */
/*   Updated: 2024/12/20 11:31:29 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		main(int argc, char **argv);
int		ft_parse_args(int argc, char **argv);
void	push_swap(t_stack a);
t_stack **ft_makelist(char **nlist, int nsize, t_stack **stack_a);

t_stack	*ft_stack_new(int number);
void	ft_stack_add_back(t_stack **lst, t_stack *new_node);
void	ft_stack_add_front(t_stack **stack, t_stack *new_node);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	ft_print_list(t_stack **lst, char name);

#endif
