/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:25:23 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/23 13:45:17 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **lst)
{
	t_node	*first;
	t_node	*last;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = *lst;
	while (last->next)
		last = last->next;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a, t_data *data)
{
	rotate(a);
	data->bm->ra += 1;
	data->bm->total_ops += 1;
	ft_putstr("ra\n", 1);
}

void	rb(t_node **b, t_data *data)
{
	rotate(b);
	data->bm->rb += 1;
	data->bm->total_ops += 1;
	ft_putstr("rb\n", 1);
}

void	rr(t_node **a, t_node **b, t_data *data)
{
	rotate(a);
	rotate(b);
	data->bm->rr += 1;
	data->bm->total_ops += 1;
	ft_putstr("rr\n", 1);
}
