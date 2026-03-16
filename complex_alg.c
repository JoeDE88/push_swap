/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:11:02 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/16 20:11:42 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	radix_sort(t_node **a, t_node **b)
{
} */

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
	lst_addback(&a, lst_new(-100));
	lst_addback(&a, lst_new(55));
	lst_addback(&a, lst_new(990));

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

	/* 	printf("\nResultado final:\n");

		tmp = a;
		while (tmp)
		{
			printf("%d (%d)", tmp->value, tmp->idx);
			if (tmp->next)
				printf(" -> ");
			tmp = tmp->next;
		} */

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