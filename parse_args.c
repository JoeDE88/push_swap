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

void	*fill_nums_arr(int ac, int flags, char **av, int *len)
{
	char	**arr;
	int		*nums_arr;
	
	if (ac == 1)
	{
		check_str(*(av+flags));
		arr = ft_split(*(av+flags), ' ', len);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	else
	{
		check_args(av, ac);
		nums_arr = nums_array(&av[flags], ac);
		*len = ac;
		if (nums_arr == NULL)
			return (NULL);
		return (nums_arr);
	}
	return (NULL);
}

int	*nums_array(char **av, int ac)
{
	int	*arr;
	int	i;

	arr = malloc(ac * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}
