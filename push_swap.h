/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:39 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/25 14:52:47 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	**safe_split(char *str, char c);
void	print_err(void);
int		count_args(char *s);
int		is_num_or_space(char c);
int		safe_atoi(char *s);
int		count_digits(char *s);

#endif