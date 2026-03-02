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
	if (!ft_strncmp(s + i, "simple", 6))
		return (2);
	if (!ft_strncmp(s + i, "medium", 6))
		return (3);
	if (!ft_strncmp(s + i, "complex", 7))
		return (4);
	if (!ft_strncmp(s + i, "adaptive", 8))
		return (1);
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
	int		not_valid;

	stack_a = NULL;
	bench = 0;
	if (ac == 1)
		return (1);
	strategy = check_params(av, &bench);
	if (strategy)
		fill_args(ac - bench - 1, av + bench + 2, &stack_a);
	else
		fill_args(ac - bench, av + bench + 1, &stack_a);
	if ((not_valid = check_repeated_or_unique(&stack_a)) != 0)
	{
		free_lst(&stack_a);
		if (not_valid == 2)
			print_err();
		return (1);
	}
	/* else
		push_swap(&stack_a); */
	return (0);
}
