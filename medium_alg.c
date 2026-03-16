/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:19:35 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/16 15:43:01 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_max_pos(t_node *b)
{
	int i;
	int max_idx;
	int max_pos;

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

void	push_chunks(t_node **a, t_node **b, int chunks_size)
{
	int i;
	
	i = 0;
	while (*a)
	{
		if ((*a)->idx <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->idx <= i + chunks_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}	
}

void push_back(t_node **a, t_node **b)
{
	int size;
	int max_pos;
	
	while (*b)
	{
		size = lst_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while(max_pos--)
				rb(b);
		}
		else
		{
			max_pos = size - max_pos;
			while(max_pos--)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunks_sort(t_node **a, t_node **b)
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
	push_chunks(a, b, chunks_size);
	push_back(a, b);
}



int	main(void)
{
	t_node *a;
	t_node *b;
	t_node *tmp;

	a = NULL;
	b = NULL;

	// Añadir nodos al frente
	lst_addback(&a, lst_new(0));
	lst_addback(&a, lst_new(4));
	lst_addback(&a, lst_new(99));
	lst_addback(&a, lst_new(-1));
	lst_addback(&a, lst_new(2));
	lst_addback(&a, lst_new(200));

	// Imprimir la lista
	printf("Lista original:\n");
	tmp = a;
	while (tmp)
	{
		printf("%d", tmp->value);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	printf("\n\nLista con indices:\n");

	index_list(&a);

	tmp = a;
	while (tmp)
	{
		printf("%d, (%d)", tmp->value, tmp->idx);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	chunks_sort(&a, &b);

	printf("\nResultado final:\n");

	tmp = a;
	while (tmp)
	{
		printf("%d (%d)", tmp->value, tmp->idx);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	//printf("\n");

	// printf("Maxima posición:%d\n", find_max_pos(a));

	// Liberar memoria
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
		while (b)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}

	return (0);
}