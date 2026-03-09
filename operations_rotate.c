/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:25:23 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/07 15:40:33 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Desplaza hacia arriba todos los elementos del stack a una posición
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

void	ra(t_node **a, int bench)
{
	rotate(a);
	if (bench)
	{
		//printf("bench: %d\n", bench);
		ft_putstr("ra\n", 2);
	}
	else
		ft_putstr("ra\n", 1);
}

void	rb(t_node **b, int bench)
{
	rotate(b);
	if (bench)
		ft_putstr("rb\n", 2);
	else
		ft_putstr("rb\n", 1);
}

//Desplaza hacia abajo todos los elementos del stack a una posición
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

void	rra(t_node **a, int bench)
{
	rev_rotate(a);
	if (bench)
		ft_putstr("rra\n", 2);
	else
		ft_putstr("rra\n", 1);
}

void	rrb(t_node **b, int bench)
{
	rev_rotate(b);
	if (bench)
		ft_putstr("rrb\n", 2);
	else
		ft_putstr("rrb\n", 1);
}

// Desplaza hacia arriba todos los elementos de ambos stacks a una posición a la vez
void	rr(t_node **a, t_node **b, int bench)
{
	rotate(a);
	rotate(b);
	if (bench)
		ft_putstr("rr\n", 2);
	else
		ft_putstr("rr\n", 1);
}

//Desplaza hacia abajo todos los elementos de ambos stacks a una posición a la vez
void	rrr(t_node **a, t_node **b, int bench)
{
	rev_rotate(a);
	rev_rotate(b);
	if (bench)
		ft_putstr("rrr\n", 2);
	else
		ft_putstr("rrr\n", 1);
}
