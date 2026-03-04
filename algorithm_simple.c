/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:22 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/04 20:10:10 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(__attribute__((unused)) t_node **dst,
		__attribute__((unused)) t_node **src)
{
	int	size;

	__attribute__((unused)) int i;
	__attribute__((unused)) int j;
	size = lstsize(*src);
	while ((*src)->next)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (a.arr[i] > a.arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*lst;
	t_node	*tmp;
	int		size;

	size = 0;
	lst = NULL;
	node1 = lst_new(2);
	node2 = lst_new(2);
	node3 = lst_new(4);
	node4 = lst_new(4);
	lst_addback(&lst, node1);
	lst_addback(&lst, node2);
	lst_addback(&lst, node3);
	lst_addback(&lst, node4);
	lst_addback(&lst, lst_new(6));
	tmp = lst;
	while (tmp)
	{
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
	size = lstsize(lst);
	printf("\n%d", size);
}
