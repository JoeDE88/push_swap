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
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
}	t_node;

// parse args
void	fill_args(int ac, char **av, t_node **lst);
int		check_params(char **av, int *bench);
// int		parse_args(int ac, char **av, int *bench, int *args_count, int *strategy);

// safe split
int		fill_arr(char **arr, char *str, char c);
int		count_args(char *s);
int		safe_malloc(char **arr, int pos, size_t len);
char	**ft_split(char *str, char c);

// err
void	print_err(void);
void	check_args(char **av, int ac);
void	check_str(char *str);
int		check_repeated_or_unique(t_node **lst);

// utils
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_atoi(char *s);
int		ft_strncmp(char *s1, char *s2, int n);

// list
void	lst_addback(t_node **lst, t_node *new);
t_node	*lst_new(int num);
void	fill_list_from_arr(t_node **lst, char **arr);

// free
void	free_arr(char **arr);
void	free_lst(t_node **lst);

// push swap
void	push_swap(t_node **lst, int strategy);
int		select_strategy(char *s);

#endif