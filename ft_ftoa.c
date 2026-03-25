/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:23:52 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/11 12:23:56 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_zero(char *str, int digits)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		str[digits] = '0';
		digits--;
		i++;
	}
	return (digits);
}

int	fill_rem_part(char *str, int rem_part, int digits)
{
	if (rem_part == 0)
		digits = fill_zero(str, digits);
	else
	{
		while (rem_part > 0)
		{
			str[digits] = (rem_part % 10) + 48;
			rem_part /= 10;
			digits--;
		}
	}
	return (digits);
}

int	fill_int_part(char *str, int int_part, int digits)
{
	if (int_part == 0)
		digits = fill_zero(str, digits);
	else
	{
		while (int_part > 0)
		{
			str[digits] = (int_part % 10) + 48;
			int_part /= 10;
			digits--;
		}
	}
	return (digits);
}

void	fill_from_double(char *str, int digits, int int_part, int rem_part)
{
	while (digits > 0)
	{
		digits = fill_rem_part(str, rem_part, digits);
		str[digits] = '.';
		digits -= 1;
		digits = fill_int_part(str, int_part, digits);
	}
}

char	*ft_ftoa(double d)
{
	char	*str;
	int		int_part;
	double	rem_part;
	int		digits;

	d *= 100;
	int_part = (int)d;
	rem_part = (d - (float)int_part);
	if (rem_part == 0 && int_part != 0)
		digits = count_digits(int_part) + 2;
	else if (int_part == 0 && rem_part != 0)
		digits = 2 + count_digits((int)(rem_part * 100));
	else if (rem_part == 0 && int_part == 0)
		digits = 4;
	else
		digits = count_digits(int_part) + count_digits((int)(rem_part * 100));
	str = ft_malloc(digits + 2);
	if (str == NULL)
		return (NULL);
	str[digits + 1] = 0;
	fill_from_double(str, digits, int_part, (int)(rem_part * 100));
	return (str);
}
