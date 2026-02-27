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
	i = 1;
	if (ac == 2)
	{
		check_str(*(av + 1));
		arr = ft_split(*(av + 1), ' ');
		fill_list_from_arr(lst, arr);
		free_arr(arr);
	}
	else
	{
		check_args(av, ac);
		while (i < ac)
		{
			num = ft_atoi(av[i]);
			lst_addback(lst, lst_new(num));
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	t_node	*args_lst;

	args_lst = NULL;
	if (ac == 1)
		return (1);
	fill_args(ac, av, &args_lst);
	if (check_repeated(&args_lst))
		/* FREE LIST AND PRINT ERROR */
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
