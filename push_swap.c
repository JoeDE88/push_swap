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

void	check_args(int ac, char **av, t_node **lst)
{
	int		i;
	int		num;
	char	**arr;

	i = 0;
	num = 0;
	if (ac == 1)
		return ;
	if (ac == 2)
	{
		arr = safe_split(*(av + 1), ' ');
		fill_lst(lst, arr);
	}
	else
	{
		while (i + 1 < ac)
		{
			num = safe_atoi(av[i + 1]);
			if (num > INT_MAX || num < INT_MIN)
				print_err();
			lst_addback(lst, lst_new(num));
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	t_node	*args_lst;
	int		i;
	int		num;

	i = 0;
	num = 0;
	args_lst = NULL;
	check_args(ac, av, &args_lst);
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
