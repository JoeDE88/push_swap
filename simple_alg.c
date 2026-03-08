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

void	simple_alg(t_node **stack, int nums, int bench)
{
	t_node	*node;
	t_node	*next;

	node = *stack;
	next = node->next;
	if (nums <= 3)
	{
		if (node->value > next->value && next->value < next->next->value)
			ra(&node);
		if (node->value > next->value && next->value > next->next->value)
		{
			ra(&node);
			sa(&node);
		}
		if (node->value < next->value && next->value > next->next->value)
			rra(&node);
	}
	else
		selection_sort(stack, NULL);
	printf("bench %d\n", bench);
}
