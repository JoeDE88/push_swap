/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:58:57 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/23 13:42:44 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_node **a, t_node **b, t_data *data)
{
	push(a, b);
	if (!data->bench)
		ft_putstr("pa\n", 1);
	else
	{
		data->bm->pa += 1;
		data->bm->total_ops += 1;
	}
}

void	pb(t_node **a, t_node **b, t_data *data)
{
	push(b, a);
	if (!data->bench)
		ft_putstr("pb\n", 1);
	else
	{
		data->bm->pb += 1;
		data->bm->total_ops += 1;
	}
}
