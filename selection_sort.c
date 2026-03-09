/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:22 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/09 15:56:53 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_node **a, t_node **b, int bench)
{
    t_node *min;
    int min_pos;
    int size;

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
            {
                if (bench)
                    ra(a, 2);
                else
                    ra(a, 1);
            }
        }
        else
        {
            while ((*a)->value != min->value)
            {
                if (bench)
                    rra(a, 2);
                else
                    rra(a, 1);
            }
        }
        if (bench)
            pb(a, b, 2);
        else
            pb(a, b, 1);
    }
    while (*b)
    {
        if (bench)
            pa(a, b, 2);
        else
           pa(a, b, 1);
    }
}
