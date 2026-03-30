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

void	parse_flags(int f_count, char **av, int *bench, char **strategy)
{
	int	i;
	int	b_flag;
	int	s_flag;

	b_flag = 0;
	s_flag = 0;
	i = 1;
	while (f_count > 0)
	{
		if (f_count > 0 && !ft_strncmp("--bench", av[i], 7))
		{
			*bench = 1;
			check_flag(&b_flag, &f_count);
			i++;
			if (!f_count && !s_flag)
				*strategy = "adaptive";
		}
		if (f_count > 0 && !ft_strncmp("--", av[i], 2))
		{
			*strategy = select_strategy(av[i]);
			check_flag(&s_flag, &f_count);
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
	else if (!ft_strncmp(s + i, "medium", 7))
		return (s + 2);
	else if (!ft_strncmp(s + i, "complex", 8))
		return (s + 2);
	else if (!ft_strncmp(s + i, "adaptive", 9))
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

void	check_flag(int *flag, int *f_count)
{
	if (*flag)
		print_err();
	else
	{
		*flag = 1;
		*f_count -= 1;
	}
}
