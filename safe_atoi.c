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

int	count_digits(char *s)
{
	int	digits;
	int	i;

	digits = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' && s[i + 1] == '\0')
			return (0);
		if (s[i] == '-')
			digits++;
		digits++;
		i++;
	}
	return (digits);
}

int	safe_atoi(char *s)
{
	long	n;
	int		digits;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	negative = 0;
	digits = count_digits(s);
	if (digits == 0)
		print_err();
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			print_err();
		n *= 10;
		n += (s[i] - 48);
		i++;
	}
	if (negative)
		return (-n);
	return (n);
}
