/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:19:35 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/15 19:24:00 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sort(t_node **a, __attribute__((unused)) t_node **b)
{
	int	size;
	int	num_chunks;
	int	chunks_size;
	int	i;

	size = lst_size(*a);
	/* 	if (size <= 100)
			num_chunks = 5;
		else
			num_chunks = 11;
		chunks_size = size / num_chunks; */
	num_chunks = ft_sqrt(size);
	chunks_size = size / num_chunks;
	if (size % num_chunks != 0)
		chunks_size++;
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
		{
			ra(a);
		}
	}
	printf("\ndentro de función: %d %d %d\n", size, num_chunks, chunks_size);
}

int	main(void)
{
	t_node *a;
	__attribute__((unused)) t_node *b;
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
	tmp = a;
	while (tmp)
	{
		printf("%d", tmp->value);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	printf("\n");

	index_list(&a);

	// Imprimir la lista
	tmp = a;
	while (tmp)
	{
		printf("%d, (%d)", tmp->value, tmp->idx);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	chunks_sort(&a, &b);

	// printf("Maxima posición:%d\n", find_max_pos(a));

	// Liberar memoria
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}