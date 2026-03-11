/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:04:11 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/09 15:42:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		free(node);
		print_err();
	}
	node->value = num;
	node->idx = 0;
	node->next = NULL;
	return (node);
}

void	lst_addback(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!new_node || !lst)
		print_err();
	last = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	if (lst && new_node)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}
void	lst_addfront(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	fill_list_from_arr(t_node **lst, char **arr)
{
	int	i;

	i = 0;
	if (!*lst)
	{
		*lst = lst_new(ft_atoi(arr[i]));
		i += 1;
	}
	while (arr[i])
	{
		lst_addback(lst, lst_new(ft_atoi(arr[i])));
		i++;
	}
}

int	lst_size(t_node *lst)
{
	int		count;
	t_node	*current_node;

	current_node = lst;
	count = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
}

