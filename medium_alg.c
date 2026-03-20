/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:41:13 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/17 16:41:14 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_alg(t_node **a, t_data *data)
{
	t_node	*stack_b;
	int		nums;

	stack_b = NULL;
	nums = lst_size(*a);
	if (nums == 2 && (*a)->value > (*a)->next->value)
		sa(a, data);
	else if (nums == 3)
		sort_three(a, data);
	else
		chunks_sort(a, &stack_b, data);
	if (stack_b)
		free_lst(&stack_b);
}
