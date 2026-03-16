/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:18:19 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/13 20:28:50 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node **stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*i_node;
	t_node	*j_node;

	i_node = *stack;
	mistakes = 0;
	total_pairs = 0;
	while (i_node != NULL && i_node->next != NULL)
	{
		j_node = i_node->next;
		while (j_node != NULL)
		{
			total_pairs++;
			if (i_node->value > j_node->value)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return (mistakes / total_pairs);
}

void	q_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int *arr, int left, int right)
{
	int	p;
	int	i;
	int	j;

	if (left >= right)
		return ;
	i = left;
	j = right;
	p = arr[left];
	while (i < j)
	{
		while (arr[i] <= p && i <= right - 1)
			i++;
		while (arr[j] > p && j >= left + 1)
			j--;
		if (i < j)
			q_swap(&arr[i], &arr[j]);
	}
	q_swap(&arr[left], &arr[j]);
	quicksort(arr, left, j - 1);
	quicksort(arr, j + 1, right);
}

void	apply_index(t_node *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
			{
				a->idx = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	index_list(t_node **a)
{
	t_node	*tmp;
	int		size;
	int		*arr;
	int		i;

	if (!a || !*a)
		return ;
	size = lst_size(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	tmp = *a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quicksort(arr, 0, size - 1);
	apply_index(*a, arr, size);
	free(arr);
}
