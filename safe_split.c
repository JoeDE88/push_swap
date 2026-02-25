/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:46:57 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/25 18:50:35 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_or_space(char c)
{
	if (!(c >= '0' && c <= '9') && c != ' ')
		return (0);
	return (1);
}

int	count_args(char *s)
{
	int	args;
	int	i;
	int	is_arg;

	args = 0;
	i = 0;
	while (s[i] != '\0')
	{
		is_arg = 0;
		if (is_num_or_space(s[i]) == 0)
			return (-1);
		while (s[i] == ' ')
			i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			if (!is_arg)
			{
				is_arg = 1;
				args++;
			}
			i++;
		}
	}
	return (args);
}

char	**safe_split(char *str, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		len;

	i = 0;
	words = count_args(str);
	if (words <= 1)
		return (NULL);
	arr = malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		len = 0;
		while (str[i] == ' ')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			len++;
		if (len)
		{
			
		}
	}
	return (arr);
}
