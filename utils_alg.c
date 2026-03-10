/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:18:19 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/10 18:26:36 by gblas-he         ###   ########.fr       */
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

void	quicksort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	while (i < j)
	{
		while (arr[i] <= pivot && i <= right - 1)
			i++;
		while (arr[j] > pivot && j >= left + 1)
			j--;
		if (i < j)
		{
			if (arr[i] >= pivot && arr[j] <= pivot)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++;
			j--;
		}
	}
}
void	index_list(t_node **a)
{
	t_node	*tmp;
	int		size;
	int		*arr;
	int		i;

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
	free(arr);
}
