/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:54:33 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/06 13:54:46 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_alg(t_node **stack_a, int bench)
{
	t_node	*node;
	t_node	*next;
	t_node	*stack_b;
	int		nums;

	node = *stack_a;
	next = node->next;
	nums = lst_size(*stack_a);
	if (nums == 2 && node->value > next->value)
		sa(&node);
	if (nums == 3)
		sort_three(stack_a, bench);	
	else
		selection_sort(stack_a, &stack_b);
}

void	sort_three(t_node **stack, int bench)
{
	t_node	*node;
	t_node	*next;

	node = *stack;
	next = node->next;
	if (node->value > next->value && next->value < next->next->value)
			ra(&node);
	if (node->value > next->value && next->value > next->next->value)
	{
		ra(&node);
		sa(&node);
	}
	if (node->value < next->value && next->value > next->next->value)
		rra(&node);
	bench = 0;
}