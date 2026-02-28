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

void	fill_args(int ac, char **av, t_node **lst)
{
	char	**arr;
	int		num;
	int		i;

	i = 1;
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

int	check_params(char **av, int *bench)
{
	int	i;
	int	strategy;

	i = 1;
	strategy = 0;
	if (!ft_strncmp(av[i], "--", 2))
	{
		if (!ft_strncmp(av[i], "--bench", 7))
		{
			*bench = 1;
			i +=1;
		}
		if (!ft_strncmp(av[i], "--", 2))
			strategy = select_strategy(av[i]);		
	}
	return (strategy);
}