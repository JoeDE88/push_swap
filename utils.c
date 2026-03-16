/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:41:38 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/16 16:59:27 by gblas-he         ###   ########.fr       */
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
		if (is_plus_or_min(s[i]))
		{
			if (s[i] == '-')
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

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_strdup(char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
