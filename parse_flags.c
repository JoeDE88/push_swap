/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:37:40 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/17 16:46:53 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!ft_strncmp("--bench", av[i], 8))
		{
			*bench = 1;
			*strategy = "adaptive";
		}
		else if (!ft_strncmp("--", av[i], 2))
			*strategy = select_strategy(av[i]);
		else
			print_err();
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
	if (!ft_strncmp(s + i, "simple", 7))
		return (s + 2);
	if (!ft_strncmp(s + i, "medium", 7))
		return (s + 2);
	if (!ft_strncmp(s + i, "complex", 8))
		return (s + 2);
	if (!ft_strncmp(s + i, "adaptive", 9))
		return (s + 2);
	else
		print_err();
	return (NULL);
}

int	count_flags(int ac, char **av)
{
	int	i;
	int	flags;

	i = 1;
	flags = 0;
	while (i < ac - 1)
	{
		if (av[i][0] == '-' && av[i][1] != '-')
			print_err();
		else
			flags++;
		i++;
	}
	return (flags);
}
