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

t_bench	*init_bench(void)
{
	t_bench	*bench_ptr;

	bench_ptr = malloc(sizeof(t_bench));
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

void	print_bench(t_algdata *data, double *disorder, char *strategy)
{
	ft_printf("[bench] disorder: %f%%\n", *disorder);
	ft_printf("[bench] strategy: %s / 0(n√n)\n", strategy);
	ft_printf("[bench] total_ops: %d\n", data->benchmark->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d", data->benchmark->sa, data->benchmark->sb, data->benchmark->ss);
	ft_printf(" pa:	%d pb: %d\n", data->benchmark->pa, data->benchmark->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d", data->benchmark->ra, data->benchmark->rb, data->benchmark->rr);
	ft_printf(" rra: %d rrb: %d rrr: %d\n", data->benchmark->rra, data->benchmark->rrb, data->benchmark->rrr);
	free(data->benchmark);
}
