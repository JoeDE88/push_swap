/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:18:19 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/10 15:50:02 by gblas-he         ###   ########.fr       */
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

void quicksort(int *arr, int left, int right)
{
	int pivot;
	int i;
	int j;
	int tmp;

	i = left;
	j = right;
	pivot = arr[(left + right)/2];
	while (arr[i] < pivot || arr[j] > pivot)
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

void	index_list(t_node **a)
{
	t_node *tmp;
	int size;
	int *arr;
	int i;

	size = lst_size(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	tmp = *a;
	i = 0;
	while(tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp-> next;
	}

	quicksort(arr, 0, size-1);
	free(arr);
} 

int main (void)
{
	t_node *a = NULL;
    t_node *tmp;

    t_node *node1 = lst_new(1);
    t_node *node2 = lst_new(2);
    t_node *node3 = lst_new(3);
	t_node *node4 = lst_new(99);
	t_node *node5 = lst_new(-1);
	t_node *node6 = lst_new(0);


    // Añadir nodos al frente
    lst_addback(&a, node1);
    lst_addback(&a, node2);
    lst_addback(&a, node3);
	lst_addback(&a, node4);
    lst_addback(&a, node5);
	lst_addback(&a, node6);

    // Imprimir la lista
    tmp = a;
    while (tmp)
    {
        printf("%d", tmp->value);
        if (tmp->next)
            printf(" -> ");
        tmp = tmp->next;
    }
    printf(" -> NULL\n");

	index_list(a);

	// Imprimir la lista
    tmp = a;
    while (tmp)
    {
        printf("%d", tmp->value);
        if (tmp->next)
            printf(" -> ");
        tmp = tmp->next;
    }
    printf(" -> NULL\n");

	// Liberar memoria
    while (a)
    {
        tmp = a->next;
        free(a);
        a = tmp;
    }
}
