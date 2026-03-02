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

/* double	compute_disorder(t_node **stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*i_node;
	t_node	*j_node;
	int		i;
	int		occ;

	i_node = *stack;
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	occ = count_occurences(stack);
	
	return (mistakes / total_pairs);
} */

void	push_swap(t_node **lst, int bench, int strategy)
{
	double	disorder;

	disorder = compute_disorder(lst);
	printf("disorder: %.1f, bench: %d, strategy: %d\n", disorder, bench, strategy);
};

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
	push_swap(&stack_a, bench, strategy);
	return (0);
}
