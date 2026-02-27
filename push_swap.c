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
 
int	select_strategy(char *s)
{
	int	i;

	i = 2;
	if (s[i] == 's')
		return (1);
	if (s[i] == 'm')
		return (2);
	if (s[i] == 'c')
		return (3);
	if (s[i] == 'a')
		return (0);
	else
		print_err();
	return (0);
}


void	push_swap(t_node **lst, int strategy)
{
	/* 	PUSH_SWAP*/
};

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	int		args_count;
	int		strategy;

	strategy = 0;
	stack_a = NULL;
	if (ac == 1)
		return (1);
	if (av[1][0] == '-' && av[1][1] == '-')
	{
		strategy = select_strategy(av[1]);
		args_count = ac - 1;
		av = av + 1;
	}
	else
		args_count = ac;
	fill_args(args_count, av, &stack_a);
	if (check_repeated(&stack_a))
		free_lst(&stack_a);
	/* else
		push_swap(&stack_a); */
/* 	if (stack_a)
	{
		while (stack_a)
		{
			printf("ARG: %d\n", stack_a->value);
			stack_a = stack_a->next;
		}	
	} */
	return (0);
}
