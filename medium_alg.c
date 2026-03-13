/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:19:35 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/13 20:28:59 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sort(t_node **a, __attribute__((unused)) t_node **b)
{
	int	size;
	int	chunks;

	size = lst_size(*a);
	chunks = ft_sqrt(size);
	printf("dentro de función: %d %d \n", size, chunks);
}

int	main(void)
{
	t_node *a;
	__attribute__((unused)) t_node *b;
	t_node *tmp;
	t_node *node1;
	t_node *node2;
	t_node *node3;
	t_node *node4;
	t_node *node5;
	t_node *node6;

	a = NULL;
	b = NULL;
	node1 = lst_new(2);
	node2 = lst_new(1);
	node3 = lst_new(3);
	node4 = lst_new(99);
	node5 = lst_new(-1);
	node6 = lst_new(0);
	// Añadir nodos al frente
	lst_addback(&a, node1);
	lst_addback(&a, node2);
	lst_addback(&a, node3);
	lst_addback(&a, node4);
	lst_addback(&a, node5);
	lst_addback(&a, node6);
	lst_addback(&a, lst_new(7));
	lst_addback(&a, lst_new(20));
	lst_addback(&a, lst_new(-10));
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