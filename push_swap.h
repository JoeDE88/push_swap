/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:39 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/07 15:44:23 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
}	t_node;

// parse args
void	fill_args(int ac, char **av, t_node **lst);
void	check_params(char **av, int *bench, int *strategy);

// safe split
int		fill_arr(char **arr, char *str, char c);
int		count_args(char *s);
int		safe_malloc(char **arr, int pos, size_t len);
char	**ft_split(char *str, char c);

// err
void	print_err(void);
void	check_args(char **av, int ac);
void	check_str(char *str);
void	check_repeated_or_unique(t_node **lst);

// utils
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_atoi(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr(char *s);

// list
void	lst_addback(t_node **lst, t_node *new);
t_node	*lst_new(int num, int i);
void	fill_list_from_arr(t_node **lst, char **arr);
int		lstsize(t_node *lst);
int		count_nums(t_node **lst);

// free
void	free_arr(char **arr);
void	free_lst(t_node **lst);

// push swap
void	push_swap(t_node **lst, int bench, int strategy);
int		select_strategy(char *s);
double	compute_disorder(t_node **stack);

// algorithms
void	simple_alg(t_node **stack, int nums, int bench);
void	medium_alg(t_node **stack, int nums, int bench);
void	complex_alg(t_node **stack, int nums, int bench);

// operations
void	swap(t_node **lst);
void	sa(t_node **a);
void	sb(t_node **b);
void 	ss(t_node **a, t_node **b);
void	push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **lst);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **lst);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

//algoritmo
void	algorithm_simple(t_node **dst, t_node **src);

#endif