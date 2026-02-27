/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:41:38 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/26 13:41:39 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

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

void	fill_list(t_node **lst, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		lst_addback(lst, lst_new(safe_atoi(arr[i])));
		i++;
	}
}
