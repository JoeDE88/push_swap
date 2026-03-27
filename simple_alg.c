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

void	simple_alg(t_node **a, t_data *data)
{
	t_node	*b;
	int		nums;

	b = NULL;
	nums = lst_size(*a);
	if (nums == 2 && (*a)->value > (*a)->next->value)
		sa(a, data);
	else if (nums == 3)
		sort_three(a, data);
	else
		selection_sort(a, &b, data);
	if (b)
		free_lst(&b);
}

void	sort_three(t_node **a, t_data *data)
{
	t_node	*next;

	next = (*a)->next;
	if ((*a)->value > next->value && next->value < next->next->value)
	{
		if ((*a)->value > next->next->value)
			ra(a, data);
		else
			sa(a, data);
	}
	if ((*a)->value > next->value && next->value > next->next->value)
	{
		ra(a, data);
		sa(a, data);
	}
	if ((*a)->value < next->value && next->value > next->next->value)
	{
		if ((*a)->value > next->next->value)
			rra(a, data);
		else
		{
			rra(a, data);
			sa(a, data);
		}
	}
}
