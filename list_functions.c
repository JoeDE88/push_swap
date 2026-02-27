/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:04:11 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/27 11:04:39 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		print_err();
	node->value = num;
	node->next = NULL;
	return (node);
}

void	lst_addback(t_node **lst, t_node *new)
{
	t_node	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	fill_list_from_arr(t_node **lst, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		lst_addback(lst, lst_new(ft_atoi(arr[i])));
		i++;
	}
}
