/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:54:33 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/10 18:21:33 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_alg(t_node **a, t_algdata *data, t_bench *bm)
{
	t_node	*stack_b;
	t_node	*next;
	int		nums;

	stack_b = NULL;
	next = (*a)->next;
	nums = lst_size(*a);
	if (nums == 2 && (*a)->value > next->value)
		sa(a, data, bm);
	else if (nums == 3)
		sort_three(a, data, bm);
	else
		selection_sort(a, &stack_b, data, bm);
	if (stack_b)
		free_lst(&stack_b);
}

void	sort_three(t_node **stack, t_algdata *data, t_bench *bm)
{
	t_node	*next;

	next = (*stack)->next;
	if ((*stack)->value > next->value && next->value < next->next->value)
	{
		if ((*stack)->value > next->next->value)
			ra(stack, data, bm);
		else
			sa(stack, data, bm);
	}
	if ((*stack)->value > next->value && next->value > next->next->value)
	{
		ra(stack, data, bm);
		sa(stack, data, bm);
	}
	if ((*stack)->value < next->value && next->value > next->next->value)
	{
		if ((*stack)->value > next->next->value)
			rra(stack, data, bm);
		else
		{
			rra(stack, data, bm);
			sa(stack, data, bm);
		}
	}
}
