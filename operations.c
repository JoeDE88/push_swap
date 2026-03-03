/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:58:57 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/02 20:09:10 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst, char *op)
{
	t_node *tmp;

	if (!lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (op)
		write(1, op, 3);
}

void	push(t_node **dest, t_node **src, char *op)
{
	t_node	*tmp;

	if (!*src)
		return ;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (op)
		write(1, op, 3);
}

void ss(t_node **lst_a, t_node **lst_b)
{
	swap(lst_a, NULL);
	swap(lst_b, NULL);
	write(1, "ss\n", 3);
}