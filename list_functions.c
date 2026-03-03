/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:04:11 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/03 19:14:27 by gblas-he         ###   ########.fr       */
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

int	lstsize(t_node *lst)
{
	int		count;
	t_node	*current_node;

	if (!lst)
		return (0);
	current_node = lst;
	count = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
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
