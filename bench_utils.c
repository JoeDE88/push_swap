/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:16:53 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/10 16:16:55 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

b_node	*init_bench(void)
{
	b_node	*bench_ptr;

	bench_ptr = malloc(sizeof(b_node));
	if (bench_ptr == NULL)
		return (NULL);
	bench_ptr->sa = 0;
	bench_ptr->sb = 0;
	bench_ptr->ss = 0;
	bench_ptr->pa = 0;
	bench_ptr->pb = 0;
	bench_ptr->ra = 0;
	bench_ptr->rb = 0;
	bench_ptr->rr = 0;
	bench_ptr->rra = 0;
	bench_ptr->rrb = 0;
	bench_ptr->rrr = 0;
	bench_ptr->total_ops = 0;
	return (bench_ptr);
}

void	print_bench(b_node *bench, double *disorder, char *strategy)
{
	int		total_ops;

	total_ops = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb;
	total_ops += bench->ra;
	total_ops += bench->rb;
	total_ops += bench->rr;
	total_ops += bench->rra;
	total_ops += bench->rrb;
	total_ops += bench->rrr;
	//s = parse_strategy(*strategy);
	ft_printf("[bench] disorder: %f%%\n", *disorder);
	ft_printf("[bench] strategy: %s / 0(nVn)\n", strategy);
	ft_printf("[bench] total_ops: %d\n", total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d", bench->sa, bench->sb, bench->ss);
	ft_printf(" pa:	%d pb: %d\n", bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d", bench->ra, bench->rb, bench->rr);
	ft_printf(" rra: %d rrb: %d rrr: %d\n", bench->rra, bench->rrb, bench->rrr);
	free(bench);
}
