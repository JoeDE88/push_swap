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
	int	bflag;
	int	sflag;

	bflag = 0;
	sflag = 0;
	i = 1;
	while (flags > 0)
	{
		if (flags > 0 && !ft_strncmp("--bench", av[i], 7))
		{
			check_flag(&bflag, &flags);
			i++;
			*bench = 1;
			if (!flags && !sflag)
				*strategy = "adaptive";
		}
		if (flags > 0 && !ft_strncmp("--", av[i], 2))
		{
			check_flag(&sflag, &flags);
			*strategy = select_strategy(av[i]);
			i++;
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
		if (av[i][0] == '-' && ft_isdigit(av[i][1]))
			break ;
		else if (av[i][0] == '-' && ft_isalpha(av[i][1]))
			print_err();
		else if (av[i][0] == '-' && av[i][1] == '-')
			flags++;
		else if (av[i][0] == '-' && av[i][1] == '\0')
			print_err();
		i++;
	}
	return (flags);
}

void	check_flag(int *flag, int *flags)
{
	if (*flag)
		print_err();
	else
	{
		*flag = 1;
		*flags -= 1;
	}
}
