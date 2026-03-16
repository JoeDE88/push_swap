#include "push_swap.h"

void    medium_alg(t_node **a, t_algdata *data, t_bench *bm)
{
    t_node  *stack_b;
    t_node  *next;
    int     nums;

    stack_b = NULL;
    next = (*a)->next;
    nums = lst_size(*a);
    if (nums == 2 && (*a)->value > next->value)
        sa(a, data, bm);
    else if (nums == 3)
        sort_three(a, data, bm);
    /* else
        chunks_sort(a, &stack_b, data, bm); */
    if (stack_b)
        free_lst(&stack_b);
}
