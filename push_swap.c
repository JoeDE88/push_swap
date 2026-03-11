/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/10 18:12:15 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b, int bench, char *strategy)
{
	double	disorder;
	b_node	*bench_ptr;

	bench_ptr = NULL;
	disorder = compute_disorder(stack_a);
	if (bench)
		bench_ptr = init_bench();
	//if (strategy == 2)
	if (!ft_strncmp(strategy, "simple", 6))
		simple_alg(stack_a, stack_b, bench, bench_ptr);
	/*if (strategy == 3)
		medium_alg(stack_a, nums, bench);
	if (strategy == 4)
		complex_alg(stack_a, nums, bench); */
	//if (strategy == 1 || strategy == 0)
	else if (!ft_strncmp(strategy, "adaptive", 8))
	{
		//if (disorder < 0.2)
			simple_alg(stack_a, stack_b, bench, bench_ptr);
		/* if (disorder >= 0.2 && disorder < 0.5)
			medium_alg(stack_a, nums, bench);
		else
			complex_alg(stack_a, nums, bench); */
	}
	if (bench)
		print_bench(bench_ptr, &disorder, strategy);
}

int	main(int ac, char *av[])
{
	t_node	*stack_a;
	int		bench;
	int		flag_strategy;
	char	*strategy;
	t_node	*stack_b;
	
	flag_strategy = 0;
	stack_a = NULL;
	stack_b = NULL;
	bench = 0;
	if (ac == 1)
		return (0);
	strategy = check_params(av, 1, &bench, &flag_strategy);
	if (flag_strategy)
		fill_args(ac - bench - 1, av + bench + 2, &stack_a);
	else
		fill_args(ac - bench, av + bench + 1, &stack_a);
	check_repeated_or_unique(&stack_a);
	if (stack_a)
	{
		// index_list(&stack_a);
		push_swap(&stack_a, &stack_b, bench, strategy);
		free_lst(&stack_a);
		free_lst(&stack_b);
	}
	return (0);
}
