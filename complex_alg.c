/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:11:02 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/17 20:06:12 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int	get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->idx;
	max_bits = 0;
	while (head)
	{
		if (head->idx > max)
			max = head->idx;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = lst_size(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->idx >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (lst_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
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

	//printf("\nMaximo bits: %d\n", get_max_bits(&a));

	radix_sort(&a,&b);

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