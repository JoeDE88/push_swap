/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:43:35 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/23 13:43:37 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **lst)
{
	t_node	*last;
	t_node	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	second_last = NULL;
	last = *lst;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_node **a, t_data *data)
{
	rev_rotate(a);
	data->bm->rra += 1;
	data->bm->total_ops += 1;
	ft_putstr("rra\n", 1);
}

void	rrb(t_node **b, t_data *data)
{
	rev_rotate(b);
	data->bm->rrb += 1;
	data->bm->total_ops += 1;
	ft_putstr("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b, t_data *data)
{
	rev_rotate(a);
	rev_rotate(b);
	data->bm->rrr += 1;
	data->bm->total_ops += 1;
	ft_putstr("rrr\n", 1);
}
