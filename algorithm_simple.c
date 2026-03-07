/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:22 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/07 13:05:55 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_node **a, t_node **b)
{
    t_node *min;
    t_node *tmp;
    int min_pos;
    int i;

// Buscar el mínimo
    while (*a)
    {
        min = *a;
        tmp = *a;
        min_pos = 0;
        i = 0;
        while (tmp)
        {
            if (tmp->value < min->value)
            {
                min = tmp;
                min_pos = i;
            }
            tmp = tmp->next;
            i++;
        }

// Mover minimo al tope por arriba o abajo
        if (min_pos <= i / 2)
        {
            while ((*a)->value != min->value)
                ra(a);
        }
        else
        {
            while ((*a)->value != min->value)
                rra(a);
        }
//push a "b"
        pb(a, b);
    }

// Volver a "a"
    while (*b)
        pa(a, b);
}

int	main(void)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*a;
	t_node	*b;
	t_node	*tmp;
	int		size;

	size = 0;
	a = NULL;
	b = NULL;
	node1 = lst_new(6);
	node2 = lst_new(2);
	node3 = lst_new(8);
	node4 = lst_new(1);
	lst_addback(&a, node1);
	lst_addback(&a, node2);
	lst_addback(&a, node3);
	lst_addback(&a, node4);
	lst_addback(&a, lst_new(6));
	tmp = a;
	while (tmp)
	{
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
	size = lstsize(a);
	printf("\n%d\n", size);
	selection_sort(&a, &b);
	tmp = a;
	while (tmp)
	{
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
}
