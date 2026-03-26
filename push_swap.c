/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/16 17:02:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_node **a, t_data *data)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		simple_alg(a, data);
	if (disorder >= 0.2 && disorder < 0.6)
		medium_alg(a, data);
	else
		complex_alg(a, data);
}

void	push_swap(t_node **stack_a, t_data *data)
{
	double	disorder;

	disorder = compute_disorder(stack_a);
	if (!disorder)
	{
		if (data->bench)
			print_bench(data, &disorder);
		free_lst(stack_a);
		return ;
	}
	if (!ft_strncmp(data->strategy, "simple", 6))
		simple_alg(stack_a, data);
	if (!ft_strncmp(data->strategy, "medium", 6))
		medium_alg(stack_a, data);
	if (!ft_strncmp(data->strategy, "complex", 7))
		complex_alg(stack_a, data);
	if (!ft_strncmp(data->strategy, "adaptive", 8))
		adaptive(stack_a, data);
	if (data->bench)
		print_bench(data, &disorder);
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_node	*stack_a;

	data = NULL;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	parse_args(&data, ac, av);
	fill_stack_from_arr(&stack_a, data);
	check_repeated_or_unique(&stack_a);
	if (stack_a)
	{
		index_list(&stack_a);
		push_swap(&stack_a, data);
		free_lst(&stack_a);
		free(data);
	}
	return (0);
}
