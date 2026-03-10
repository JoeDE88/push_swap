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

void	simple_alg(t_node **stack_a, int bench, b_node *bench_ptr)
{
	t_node	*node;
	t_node	*next;
	t_node	*stack_b;
	int		nums;

	node = *stack_a;
	next = node->next;
	stack_b = NULL;
	nums = lst_size(*stack_a);
	if (nums == 2 && node->value > next->value)
		sa(&node, bench, bench_ptr);
	else if (nums == 3)
		sort_three(stack_a, bench, bench_ptr);	
	else
		selection_sort(stack_a, &stack_b, bench, bench_ptr);
}

void	sort_three(t_node **stack, int bench, b_node *bench_ptr)
{
	t_node *node;
	t_node *next;

	node = *stack;
	next = node->next;
	if (node->value > next->value && next->value < next->next->value)
		ra(&node, bench, bench_ptr);
	if (node->value > next->value && next->value > next->next->value)
	{
		ra(&node, bench, bench_ptr);
		sa(&node, bench, bench_ptr);
	}
	if (node->value < next->value && next->value > next->next->value)
		rra(&node, bench, bench_ptr);
}