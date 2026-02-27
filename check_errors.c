/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:18:47 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/27 11:58:10 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			print_err();
	}
}

void	check_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_str(av[i]);
		i++;
	}
}

int	check_repeated(t_node **lst)
{
	t_node	*i_node;
	t_node	*j_node;

	i_node = *lst;
	while (i_node->next != NULL)
	{
		j_node = i_node->next;
		while (j_node != NULL)
		{
			if (j_node->value == i_node->value)
				return (1);
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return (0);
}
