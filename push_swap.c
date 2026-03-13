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

void	adaptive(t_node **a, int bench, t_bench *bench_ptr)
{
	double	disorder;

	disorder = compute_disorder(a);
	//if (disorder < 0.2)
		simple_alg(a, bench, bench_ptr);
	/* if (disorder >= 0.2 && disorder < 0.5)
			medium_alg(stack_a, bench, bench_ptr);
	else
		complex_alg(stack_a, bench, bench_ptr); */
	printf("dis: %f\n", disorder);
}

void	push_swap(t_node **stack_a, int bench, char *strategy)
{
	t_bench	*bench_ptr;
	double	disorder;

	bench_ptr = NULL;
	disorder = compute_disorder(stack_a);
	if (!disorder)
	{
		free_lst(stack_a);
		return ;
	}
	if (bench)
		bench_ptr = init_bench();
	if (!ft_strncmp(strategy, "simple", 6))
		simple_alg(stack_a, bench, bench_ptr);
	/*if (!ft_strncmp(strategy, "medium", 6))
		medium_alg(stack_a, stack_b, bench, bench_ptr);
	if (!ft_strncmp(strategy, "complex", 7))
		complex_alg(stack_a, stack_b, bench, bench_ptr); */
	else if (!ft_strncmp(strategy, "adaptive", 8))
		adaptive(stack_a, bench, bench_ptr);
	if (bench)
		print_bench(bench_ptr, &disorder, strategy);
}

int	main(int ac, char *av[])
{
	t_node		*stack_a;
	//t_algdata	*data;
	 int		bench;
	int		flag_strategy;
	char	*strategy;

	flag_strategy = 0;
	stack_a = NULL;
	bench = 0;
	if (ac == 1)
		return (0);
	/* data = parse_args(ac, av);
	printf("stra: %s\n", data->strategy); */
	strategy = check_params(av, 1, &bench, &flag_strategy);
	if (flag_strategy)
		fill_args(ac - bench - 1, av + bench + 2, &stack_a);
	else
		fill_args(ac - bench, av + bench + 1, &stack_a);
	check_repeated_or_unique(&stack_a);
	if (stack_a)
	{
		// index_list(&stack_a);
		push_swap(&stack_a, bench, strategy);
		free_lst(&stack_a);
	}
	free(strategy);
	return (0);
}
