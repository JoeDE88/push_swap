/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/26 16:24:16 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_args(int ac, char **av, t_node **lst)
{
	char	**arr;
	int		num;
	int		i;

	num = 0;
	i = 0;
	if (ac == 1)
		return ;
	if (ac == 2)
	{
		arr = safe_split(*(av + 1), ' ');
		fill_list(lst, arr);
		free_arr(arr);
	}
	else
	{
		while (i + 1 < ac)
		{
			num = safe_atoi(av[i + 1]);
			lst_addback(lst, lst_new(num));
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	t_node	*args_lst;
	t_node	*head;

	args_lst = NULL;
	fill_args(ac, av, &args_lst);
	/* check for REPEATED NUMS and if so, FREE LIST*/
	
	/*  */
	head = args_lst;
	if (args_lst)
	{
		while (args_lst != NULL)
		{
			printf("arg st: %d\n", args_lst->value);
			args_lst = args_lst->next;
		}
	}
	return (0);
}
