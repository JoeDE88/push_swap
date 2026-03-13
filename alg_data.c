#include "push_swap.h"

t_algdata   *fill_alg_data(int benchmark, char *strategy)
{
    t_algdata   *data;

    data = malloc(sizeof(t_algdata));
    if (data == NULL)
        return (NULL);
    data->bench = benchmark;
    data->strategy = strategy;
    return (data);
}
