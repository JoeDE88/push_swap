/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:48:19 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/11 11:48:21 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert(va_list args, char specifier)
{
	if (specifier == 'd')
		ft_printint(va_arg(args, int));
	if (specifier == 's')
		ft_printstr(va_arg(args, char *));
	if (specifier == '%')
		ft_printchar('%');
	if (specifier == 'f')
		ft_printdouble(va_arg(args, double));
}

void	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;

	i = 0;
	if (!format || (format[i] == '%' && format[i + 1] == '\0'))
		return ;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				convert(args, format[i + 1]);
				i++;
			}
		}
		else
			ft_printchar(format[i]);
		i++;
	}
	va_end(args);
}
