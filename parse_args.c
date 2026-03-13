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

int	*fill_nums_arr(int ac, int flags, char **av)
{
	int	i;

	i = 1;
	printf("ac: %d\n", ac);
	printf("av[ac]: %s\n", av[i + flags]);
	
	return (NULL);
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
		if (arr == NULL)
			return ;
		fill_list_from_arr(lst, arr);
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

void	check_bench(char *av, int *bench)
{
	if (!ft_strncmp(av, "--bench", 7))
		*bench = 1;
	else
		*bench = 0;
}

char	*check_strategy(char *av, int *flag_strategy)
{
	char	*strat;

	if (!ft_strncmp(av, "--", 2))
	{
		strat = ft_strdup(select_strategy(av));
		*flag_strategy = 1;
	}
	else
		strat = ft_strdup("adaptive");
	return (strat);
}

char	*check_params(char **av, int ac, int *bench, int *strategy)
{
	char	*strat;

	check_bench(av[ac], bench);
	if (*bench)
		strat = check_strategy(av[ac + 1], strategy);
	else
	{
		strat = check_strategy(av[ac], strategy);
		if (av[ac + 1] != NULL)
			check_bench(av[ac + 1], bench);
	}
	return (strat);
}
