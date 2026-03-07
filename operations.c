/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:58:57 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/07 13:05:53 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intercambia los dos primeros elementos del stack
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

void	sa(t_node **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_putstr("sb\n");
}

// Toma el primer elemento del 1º stack y lo coloca el primero en el 2º stack
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

<<<<<<< HEAD
void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_putstr("pb\n");
}

// Intercambia los dos primeros elementos de ambos stacks a la vez
void ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
=======
void	ss(t_node **lst_a, t_node **lst_b)
{
	swap(lst_a, NULL);
	swap(lst_b, NULL);
	write(1, "ss\n", 3);
}
>>>>>>> main
