/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:37:40 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/16 17:37:42 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algdata	*parse_args(t_algdata **data, int ac, char **av)
{
	void	*nums;
	int		flags;
	int		bench;
	int		len;
	char	*strategy;

	bench = 0;
	len = 0;
	flags = count_flags(ac, av);
	parse_flags(flags, av, &bench, &strategy);
	nums = fill_nums_arr(ac - 1 - flags, flags, av + 1, &len);
	if (ac == 2)
		*data = fill_alg_data(bench, strategy, nums, 0, len);
	else
		*data = fill_alg_data(bench, strategy, nums, 1, len);
	if (*data == NULL)
		print_err();
	return (*data);
}

void	parse_flags(int flags, char **av, int *bench, char **strategy)
{
	int	i;

	i = 1;
	if (flags > 2)
		print_err();
	if (flags == 0)
		*strategy = "adaptive";
	if (flags == 1)
	{
		if (!ft_strncmp("--bench", av[i], 7))
		{
			*bench = 1;
			*strategy = "adaptive";
		}
		else if (!ft_strncmp("--", av[i], 2))
			*strategy = select_strategy(av[i]);
	}
	else
		loop_flags(flags, av, bench, strategy);
}

void	loop_flags(int flags, char **av, int *bench, char **strategy)
{
	int	i;

	i = 1;
	while (flags > 0)
	{
		if (!ft_strncmp("--bench", av[i], 7))
		{
			*bench = 1;
			flags--;
			i++;
		}
		if (!ft_strncmp("--", av[i], 2))
		{
			*strategy = select_strategy(av[i]);
			i++;
			flags--;
		}
	}
}

char	*select_strategy(char *s)
{
	int	i;

	i = 2;
	if (!ft_strncmp(s + i, "simple", 6))
		return (s + 2);
	if (!ft_strncmp(s + i, "medium", 6))
		return (s + 2);
	if (!ft_strncmp(s + i, "complex", 7))
		return (s + 2);
	if (!ft_strncmp(s + i, "adaptive", 8))
		return (s + 2);
	else
		print_err();
	return (NULL);
}

int	count_flags(int ac, char **av)
{
	int	i;
	int	flags;

	i = 0;
	flags = 0;
	while (i++ < ac - 1)
	{
		if (!ft_strncmp(av[i], "--", 2))
			flags++;
	}
	return (flags);
}
