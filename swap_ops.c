/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:40:59 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst)
{
	t_node	*tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	sa(t_node **a, t_data *data)
{
	swap(a);
	if (data->bench)
	{
		data->bm->sa += 1;
		data->bm->total_ops += 1;
	}
	ft_putstr("sa\n", 1);
}

void	sb(t_node **b, t_data *data)
{
	swap(b);
	if (data->bench)
	{
		data->bm->sb += 1;
		data->bm->total_ops += 1;
	}
	ft_putstr("sb\n", 1);
}

void	ss(t_node **a, t_node **b, t_data *data)
{
	swap(a);
	swap(b);
	if (data->bench)
	{
		data->bm->ss += 1;
		data->bm->total_ops += 1;
	}
	ft_putstr("ss\n", 1);
}
