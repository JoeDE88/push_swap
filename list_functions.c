/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:04:11 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/09 13:46:47 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int num, int i)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		print_err();
	node->value = num;
	node->idx = i;
	node->next = NULL;
	return (node);
}

void	lst_addback(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new || !lst)
		print_err();
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
		lst_addback(lst, lst_new(ft_atoi(arr[i]), i));
		i++;
	}
}

int	lstsize(t_node *lst)
{
	int		count;
	t_node	*current_node;

	if (!lst)
		print_err();
	current_node = lst;
	count = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
}
int	count_nums(t_node **lst)
{
	t_node	*node;
	int		nums;

	node = *lst;
	nums = 0;
	while (node)
	{
		nums++;
		node = node->next;
	}
	return (nums);
}
