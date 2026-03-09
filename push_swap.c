/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/09 15:40:43 by gblas-he         ###   ########.fr       */
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

void	push_swap(t_node **stack_a, int bench, int strategy)
{
	int		nums;
	double	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder == 0)
		return ;
	nums = lst_size(*stack_a);
	/* if (strategy == 2)
		simple_alg(stack_a, nums, bench);
	if (strategy == 3)
		medium_alg(stack_a, nums, bench);
	if (strategy == 4)
		complex_alg(stack_a, nums, bench); */
	if (strategy == 1 || strategy == 0)
	{
		// if (disorder < 0.2)
		simple_alg(stack_a, nums, bench);
		/* if (disorder >= 0.2 && disorder < 0.5)
			medium_alg(stack_a, nums, bench);
		else
			complex_alg(stack_a, nums, bench); */
	}
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	int		bench;
	int		strategy;

	stack_a = NULL;
	bench = 0;
	strategy = 0;
	if (ac == 1)
		return (0);
	check_params(av, &bench, &strategy);
	if (strategy)
		fill_args(ac - bench - 1, av + bench + 2, &stack_a);
	else
		fill_args(ac - bench, av + bench + 1, &stack_a);
	check_repeated_or_unique(&stack_a);
	if (stack_a)
	{
		//index_list(&stack_a);
		push_swap(&stack_a, bench, strategy);
	}
	return (0);
}
