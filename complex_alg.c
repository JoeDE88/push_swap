/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:11:02 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/18 20:32:15 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *a)
{
	int	max_idx;

	__attribute__((unused)) int max_bits;
	max_bits = 0;
	max_idx = a->idx;
	while (a)
	{
		if (a->idx > max_idx)
			max_idx = a->idx;
		a = a->next;
	}
	while (max_idx >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int		size;
	int		max_bits;
	t_node	*tmp;
	int		i;
	int		j;

	size = lst_size(*a);
	max_bits = get_max_bits(*a);
	tmp = *a;
	i = 0;
	printf("\npruebas: %d\n", max_bits);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((tmp->idx >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
		{
			pa(a, b);
			*b = (*b)->next;
		}
		i++;
	}
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
	lst_addback(&a, lst_new(300));
	lst_addback(&a, lst_new(400));
	lst_addback(&a, lst_new(-200));
	lst_addback(&a, lst_new(1000));

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

	printf("\nLista con indices:\n");

	index_list(&a);

	tmp = a;
	while (tmp)
	{
		printf("%d, (%d)", tmp->value, tmp->idx);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

	// printf("\nMaximo bits: %d\n", get_max_bits(&a));

	radix_sort(&a, &b);

	printf("\nResultado final:\n");

	tmp = a;
	while (tmp)
	{
		printf("%d (%d)", tmp->value, tmp->idx);
		if (tmp->next)
			printf(" -> ");
		tmp = tmp->next;
	}

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