#include "push_swap.h"

t_algdata   *parse_args(int ac, char **av)
{
    t_algdata   *data;
    int         *nums;
    int         flags;
    int         bench;
    int         i;
    char        *strategy;

    flags = 0;
    bench = 0;
    i = 0;
    while (i++ < ac - 1)
    {
        if (!ft_strncmp(av[i], "--", 2))
            flags++;
    }
    parse_flags(flags, av, &bench, &strategy);
    nums = fill_nums_arr(ac - flags, flags, av);
    printf("nums: %d\n", *nums);
    data = fill_alg_data(bench, strategy);
    if (data == NULL)
        print_err();
    return (data);
}

void    parse_flags(int flags, char **av, int *bench, char **strategy)
{
    int i;

    i = 1;
    if (flags > 2)
        print_err();
    if (flags == 0)
        *strategy = "adaptive";
    if (flags == 1)
    {
        if (!ft_strncmp("--bench", av[i], 7))
        {
            *bench = 1;
            *strategy = "adaptive";
        }
        else if (!ft_strncmp("--", av[i], 2))
            *strategy = select_strategy(av[i]);
    }
    else
        loop_flags(flags, av, bench, strategy);
}

void    loop_flags(int flags, char **av, int *bench, char **strategy)
{
    int i;

    i = 1;
    while (flags > 0)
    {
        if (!ft_strncmp("--bench", av[i], 7))
        {
            *bench = 1;
            flags--;
            i++;
        }
        if (!ft_strncmp("--", av[i], 2))
        {
            *strategy = select_strategy(av[i]);
            i++;
            flags--;
        }
    }
}
/* char	*select_strategy(char *s)
{
	int	i;

	i = 2;
	if (!ft_strncmp(s + i, "simple", 6))
		return (s + 2);
	if (!ft_strncmp(s + i, "medium", 6))
		return (s + 2);
	if (!ft_strncmp(s + i, "complex", 7))
		return (s + 2);
	if (!ft_strncmp(s + i, "adaptive", 8))
		return (s + 2);
	else
		print_err();
	return (NULL);
} */
