/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/25 14:52:07 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	**stack_args;
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		stack_args = safe_split(av[1], ' ');
		if (stack_args == NULL)
			print_err();
	}
	else
	{
		while (i < ac)
		{	
			printf("%d\n", safe_atoi(av[i]));
			i++;
		}
	}
	
	return (0);
}
