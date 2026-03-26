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

void	print_bench(t_data *data, double *disorder)
{
	ft_printf("[bench] disorder: %f%%\n", *disorder);
	ft_printf("[bench] strategy: %s / ", data->strategy);
	ft_printf("%s\n", compute_complexity(data, disorder));
	ft_printf("[bench] total_ops: %d\n", data->bm->total_ops);
	ft_printf("[bench] sa: %d sb: %d", data->bm->sa, data->bm->sb);
	ft_printf(" ss: %d", data->bm->ss);
	ft_printf(" pa:	%d pb: %d\n", data->bm->pa, data->bm->pb);
	ft_printf("[bench] ra: %d rb: %d", data->bm->ra, data->bm->rb);
	ft_printf(" rr: %d rra: %d", data->bm->rr, data->bm->rra);
	ft_printf(" rrb: %d rrr: %d\n", data->bm->rrb, data->bm->rrr);
	free(data->bm);
}

char	*compute_complexity(t_data *data, double *disorder)
{
	int	dis;

	dis = *disorder * 100;
	if (!ft_strncmp(data->strategy, "adaptive", 8))
	{
		if (dis < 20)
			return ("O(n2)");
		if (dis >= 20 && dis < 60)
			return ("O(n√n)");
		else
			return ("O(nlogn)");
	}
	if (!ft_strncmp(data->strategy, "simple", 6))
		return ("O(n2)");
	if (!ft_strncmp(data->strategy, "medium", 6))
		return ("O(n√n)");
	if (!ft_strncmp(data->strategy, "complex", 7))
		return ("O(nlogn)");
	return (NULL);
}
