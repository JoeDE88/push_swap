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

b_node *init_bench(void)
{
	b_node *bench_ptr;

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

void	print_bench(b_node *bench)
{
	char *s;

	write(2, "[bench] disorder: ", 18);
	s = ft_itoa(bench->sa);
	write(2, "sa: ", 4);
	write(2, s, ft_strlen(s));
}