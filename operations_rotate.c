/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:25:23 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/02 19:56:01 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **lst, char *op)
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
	if (op)
		write(1, op, 3);
}

void	reverse_rotate(t_node **lst, char *op)
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
	if (op)
		write(1, op, 4);
}

void	rr(t_node **lst_a, t_node **lst_b)
{
	rotate(lst_a, NULL);
	rotate(lst_b, NULL);
	write(1, "rr\n", 3);
}

void	rrr(t_node **lst_a, t_node **lst_b)
{
	reverse_rotate(lst_a, NULL);
	reverse_rotate(lst_b, NULL);
	write(1, "rrr\n", 4);
}
