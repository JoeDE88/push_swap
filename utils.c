/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:41:38 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/26 13:41:39 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	ft_atoi(char *s)
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

int		ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}