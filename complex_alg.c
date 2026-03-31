/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:11:02 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/19 12:03:38 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_alg(t_node **a, t_data *data)
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
		radix_sort(a, &b, data);
	if (b)
		free_lst(&b);
}

int	get_max_bits(t_node *a)
{
	int	max_idx;
	int	max_bits;

	max_bits = 0;
	max_idx = a->idx;
	while (a)
	{
		if (a->idx > max_idx)
			max_idx = a->idx;
		a = a->next;
	}
	if (max_idx == 0)
		return (1);
	while (max_idx >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **a, t_node **b, t_data *data)
{
	int		size;
	int		max_bits;
	t_node	*tmp;
	int		i;
	int		j;

	size = lst_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size && !isordered(a))
		{
			tmp = *a;
			if (((tmp->idx >> i) & 1) == 1)
				ra(a, data);
			else
				pb(a, b, data);
		}
		while (*b)
			pa(a, b, data);
		i++;
	}
}
