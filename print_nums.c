/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:03:51 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/11 12:07:13 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printint(int n)
{
	char	*s;

	s = ft_itoa(n);
	ft_printstr(s);
	free(s);
}

void	ft_printdouble(double d)
{
	char	*s;

	s = ft_ftoa(d);
	ft_printstr(s);
	free(s);
}