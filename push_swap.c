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

int	select_strategy(char *s)
{
	int	i;

	i = 2;
	if (!ft_strncmp(s+i, "simple", 6))
		return (1);
	if (!ft_strncmp(s+i, "medium", 6))
		return (2);
	if (!ft_strncmp(s+i, "complex", 7))
		return (3);
	if (!ft_strncmp(s+i, "adaptive", 8))
		return (0);
	else
		print_err();
	return (0);
}

/* 	PUSH_SWAP
void	push_swap(t_node **lst, int strategy)
{
};
*/

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	int		bench;
	int		strategy;

	stack_a = NULL;
	bench = 0;
	if (ac == 1)
		return (1);
	strategy = check_params(av, &bench);
	if ((bench && !strategy) || (!bench && strategy))
		fill_args(ac - 1, av + 2, &stack_a);
	if (bench && strategy)
		fill_args(ac - 2, av + 3, &stack_a);
	if (check_repeated_or_unique(&stack_a))
	{
		free_lst(&stack_a);
		print_err();
	}
	/* else
		push_swap(&stack_a); */
	if (stack_a)
		printf("OK");
	return (0);
}
