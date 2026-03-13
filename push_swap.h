/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:39 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/09 18:20:28 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
}	t_node;

typedef struct s_algdata
{
	int		*arr;
	int		bench;
	char	*strategy;
}	t_algdata;

t_algdata   *parse_args(int ac, char **av);
t_algdata   *fill_alg_data(int benchmark, char *strategy);
void    	parse_flags(int flags, char **av, int *bench, char **strategy);
void    	loop_flags(int flags, char **av, int *bench, char **strategy);
int			*fill_nums_arr(int ac, int flags, char **av);
// bench
typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_ops;
}	t_bench;

t_bench	*init_bench(void);
void	print_bench(t_bench *bench, double *disorder, char *strategy);

// ft_printf
void	ft_printf(const char *format, ...);
void	convert(va_list args, char specifier);
void	ft_printchar(char c);
void	ft_printstr(char *s);
void	ft_printint(int n);
void	ft_printdouble(double n);

// parse args
void	fill_args(int ac, char **av, t_node **lst);
char	*check_params(char **av, int ac, int *bench, int *strategy);
char	*select_strategy(char *s);
void	check_bench(char *av, int *bench);
char	*check_strategy(char *av, int *flag_strategy);

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
int		is_plus_or_min(int c);
int		ft_isdigit(int c);
int		ft_atoi(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_ftoa(double d);
size_t	ft_strlen(char *s);
int		count_digits(long n);
char	*ft_malloc(int n);
void	fill_from_double(char *str, int digits, int int_part, int rem_part);
char	*ft_strdup(char *str);

// list
void	lst_addback(t_node **lst, t_node *new_node);
t_node	*lst_new(int num);
void	fill_list_from_arr(t_node **lst, char **arr);
int		lst_size(t_node *lst);

// free
void	free_arr(char **arr);
void	free_lst(t_node **lst);

// push swap
void	push_swap(t_node **stack_a, int bench, char *strategy);
double	compute_disorder(t_node **stack);

// algorithms
void	simple_alg(t_node **a, int bench, t_bench *bench_ptr);
void	medium_alg(t_node **stack_a, int bench, t_bench *bench_ptr);
void	complex_alg(t_node **stack_a, int bench, t_bench *bench_ptr);

// operations
void	swap(t_node **lst);
void	sa(t_node **a, int bench, t_bench *bench_ptr);
void	sb(t_node **b, int bench, t_bench *bench_ptr);
void	ss(t_node **a, t_node **b, int bench, t_bench *bench_ptr);
void	push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b, int bench, t_bench *bench_ptr);
void	pb(t_node **a, t_node **b, int bench, t_bench *bench_ptr);
void	rotate(t_node **lst);
void	ra(t_node **a, int bench, t_bench *bench_ptr);
void	rb(t_node **b, int bench, t_bench *bench_ptr);
void	rr(t_node **a, t_node **b, int bench, t_bench *bench_ptr);
void	rev_rotate(t_node **lst);
void	rra(t_node **a, int bench, t_bench *bench_ptr);
void	rrb(t_node **b, int bench, t_bench *bench_ptr);
void	rrr(t_node **a, t_node **b, int bench, t_bench *bench_ptr);

//algoritmos
void	adaptive(t_node **a, int bench, t_bench *bench_ptr);
void	sort_three(t_node **stack, int bench, t_bench *bench_ptr);
void	selection_sort(t_node **a, t_node **b, int bench, t_bench *bench_ptr);

#endif