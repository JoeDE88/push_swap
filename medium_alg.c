/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:19:35 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/14 21:52:27 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sort(t_node **a, __attribute__((unused)) t_node **b)
{
	int	size;
	int	num_chunks;
	int	chunks_size;

	size = lst_size(*a);
	/* 	if (size <= 100)
			num_chunks = 5;
		else
			num_chunks = 11; */
	num_chunks = ft_sqrt(size);
	chunks_size = size / num_chunks;
	if (size % num_chunks != 0)
		chunks_size++;
	printf("dentro de función: %d %d %d\n", size, num_chunks, chunks_size);
}

int	main(void)
{
	t_node *a;
	__attribute__((unused)) t_node *b;
	t_node *tmp;

	a = NULL;
	b = NULL;

	// Añadir nodos al frente
	lst_addback(&a, lst_new(-1));
	lst_addback(&a, lst_new(7));
	lst_addback(&a, lst_new(5));
	lst_addback(&a, lst_new(2));
	lst_addback(&a, lst_new(3));

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
	index_list(&a);
	chunks_sort(&a, &b);

	// Imprimir la lista
	tmp = a;
	while (tmp)
	{
		printf("%d, (%d)", tmp->value, tmp->idx);
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