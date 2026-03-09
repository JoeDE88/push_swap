/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:58:57 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/07 15:42:40 by gblas-he         ###   ########.fr       */
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

void	sa(t_node **a, int bench)
{
	swap(a);
	if (bench)
		ft_putstr("sa\n", 2);
	else
		ft_putstr("sa\n", 1);
}

void	sb(t_node **b, int bench)
{
	swap(b);
	if (bench)
	ft_putstr("sb\n", 2);
		else
	ft_putstr("sb\n", 1);
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

void	pa(t_node **a, t_node **b, int bench)
{
	push(a, b);
	if (bench)
		ft_putstr("pa\n", 2);
	else
		ft_putstr("pa\n", 1);
}

void	pb(t_node **a, t_node **b, int bench)
{
	push(b, a);
	if (bench)
		ft_putstr("pb\n", 2);
	else
		ft_putstr("pb\n", 1);
}

// Intercambia los dos primeros elementos de ambos stacks a la vez
void ss(t_node **a, t_node **b, int bench)
{
	swap(a);
	swap(b);
	if (bench)
		ft_putstr("ss\n", 2);
	else
		ft_putstr("ss\n", 1);
}
