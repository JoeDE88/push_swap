/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:19:35 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/16 16:58:35 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_node *b)
{
	int	i;
	int	max_idx;
	int	max_pos;

	if (!b)
		return (-1);
	i = 0;
	max_idx = b->idx;
	max_pos = 0;
	while (b)
	{
		if (b->idx > max_idx)
		{
			max_idx = b->idx;
			max_pos = i;
		}
		b = b->next;
		i++;
	}
	return (max_pos);
}

void	push_chunks(t_node **a, t_node **b, int chunks_size, t_data *data)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->idx <= i)
		{
			pb(a, b, data);
			rb(b, data);
			i++;
		}
		else if ((*a)->idx <= i + chunks_size)
		{
			pb(a, b, data);
			i++;
		}
		else
			ra(a, data);
	}
}

void	push_back(t_node **a, t_node **b, t_data *data)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = lst_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
				rb(b, data);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
				rrb(b, data);
		}
		pa(a, b, data);
	}
}

void	chunks_sort(t_node **a, t_node **b, t_data *data)
{
	int	size;
	int	num_chunks;
	int	chunks_size;

	size = lst_size(*a);
	if (size <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	chunks_size = size / num_chunks;
	if (size % num_chunks)
		chunks_size++;
	push_chunks(a, b, chunks_size, data);
	push_back(a, b, data);
}
