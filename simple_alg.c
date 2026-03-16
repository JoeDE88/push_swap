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

void	simple_alg(t_node **a, int bench, t_bench *bench_ptr)
{
	t_node	*stack_b;
	t_node	*next;
	int		nums;

	stack_b = NULL;
	next = (*a)->next;
	nums = lst_size(*a);
	if (nums == 2 && (*a)->value > next->value)
		sa(a, bench, bench_ptr);
	else if (nums == 3)
		sort_three(a, bench, bench_ptr);
	else
		selection_sort(a, &stack_b, bench, bench_ptr);
	if (stack_b)
		free_lst(&stack_b);
}

void	sort_three(t_node **stack, int bench, t_bench *bench_ptr)
{
	t_node	*next;

	next = (*stack)->next;
	if ((*stack)->value > next->value && next->value < next->next->value)
		ra(stack, bench, bench_ptr);
	if ((*stack)->value > next->value && next->value > next->next->value)
	{
		ra(stack, bench, bench_ptr);
		sa(stack, bench, bench_ptr);
	}
	if ((*stack)->value < next->value && next->value > next->next->value)
		rra(stack, bench, bench_ptr);
}
