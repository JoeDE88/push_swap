/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:22 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/07 15:47:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_node **a, t_node **b)
{
    t_node *min;
    t_node *tmp;
    int min_pos;
    int i;

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
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}
