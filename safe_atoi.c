/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:24:00 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/25 17:24:01 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_atoi(char *s)
{
	long	n;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	negative = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			negative = 1;
			i++;
		}
		if (!(s[i] >= '0' && s[i] <= '9'))
			print_err();
		n *= 10;
		n += (s[i] - 48);
		i++;
	}
	if (negative)
		n *= -1;
	if (n > INT_MAX || n < INT_MIN)
		print_err();
	return (n);
}
