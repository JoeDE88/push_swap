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

void	simple_alg(t_node **stack_a, int nums, int bench)
{
	t_node	*node;
	t_node	*next;
	t_node	*stack_b;

	node = *stack_a;
	next = node->next;
	if (nums <= 3)
	{
		if (node->value > next->value && next->value < next->next->value)
			ra(&node, bench);
		if (node->value > next->value && next->value > next->next->value)
		{
			ra(&node, bench);
			sa(&node, bench);
		}
		if (node->value < next->value && next->value > next->next->value)
			rra(&node, bench);
	}
	else
		selection_sort(stack_a, &stack_b, bench);
}
