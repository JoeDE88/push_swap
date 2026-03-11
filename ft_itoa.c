/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:26:56 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/10 16:26:58 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill(char *s, int digits, long nbr);

int	count_digits(long n)
{
	int		digits;

	digits = 0;
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	if (n == 0)
		digits++;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_malloc(int n)
{
	char	*ptr;

	ptr = malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}

static void	ft_fill(char *s, int digits, long nbr)
{
	while (digits > 0)
	{
		s[digits - 1] = (nbr % 10) + 48;
		nbr /= 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	nbr;
	int		is_negative;

	nbr = n;
	is_negative = 0;
	digits = count_digits(nbr);
	if (nbr < 0)
	{
		nbr *= -1;
		str = ft_malloc(digits);
		is_negative = 1;
	}
	else
		str = ft_malloc(digits);
	if (str == NULL)
		return (NULL);
	str[digits] = 0;
	ft_fill(str, digits, nbr);
	if (is_negative)
		str[0] = '-';
	return (str);
}
