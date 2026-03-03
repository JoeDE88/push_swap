/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:04:27 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/03 19:14:47 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	computer_disorder(t_node **lst)
{
	int mistakes;
	int total_pairs;
	int size;
	int i;
	int j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	size = lstsize(*lst);
	while (i < a.size)
	{
		j = i + 1;
		while (j < a.size)
		{
			total_pairs++;
			if (a.arr[i] > a.arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}