/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:27:48 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/28 16:27:50 by jdiaz-ec         ###   ########.fr       */
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

void	fill_args(int ac, char **av, t_node **lst)
{
	char	**arr;
	int		num;
	int		i;

	i = 0;
	if (ac == 2)
	{
		check_str(*(av));
		arr = ft_split(*(av), ' ');
		fill_list_from_arr(lst, arr);
		free_arr(arr);
	}
	else
	{
		check_args(av, ac - 1);
		while (i < ac - 1)
		{
			num = ft_atoi(av[i]);
			lst_addback(lst, lst_new(num));
			i++;
		}
	}
}

void	check_params(char **av, int ac, int *bench, int *strategy)
{
	if (!ft_strncmp(av[ac], "--bench", 7))
	{
		*bench = 1;
		ac += 1;
		if (!ft_strncmp(av[ac], "--", 2))
			*strategy = select_strategy(av[ac]);
	}
	else
	{
		if (!ft_strncmp(av[ac], "--", 2))
		{
			*strategy = select_strategy(av[ac]);
			ac += 1;
		}
		if (!ft_strncmp(av[ac], "--bench", 7))
			*bench = 1;
	}
}
