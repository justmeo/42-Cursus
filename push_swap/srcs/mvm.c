

#include "../include/push_swap.h"

void sa(int *a, int len_a)
{
    int temp;
    if (len_a > 1)
    {
        temp = a[0];
        a[0] = a[1];
        a[1] = temp;
        printf("sa\n");
    }
}

void sb(int *b, int len_b)
{
    int temp;
    if (len_b > 1)
    {
        temp = b[0];
        b[0] = b[1];
        b[1] = temp;
        printf("sb\n");
    }
}

void ss(int *a, int len_a, int *b, int len_b)
{
    sa(a, len_a);
    sb(b, len_b);
    printf("ss\n");
}

void pa(int **a, int *len_a, int **b, int *len_b)
{
    int *temp;
    if (*len_b > 0)
    {
        temp = (int *)malloc(sizeof(int) * (*len_a + 1));
        memcpy(temp + 1, *a, sizeof(int) * (*len_a));
        temp[0] = (*b)[0];
        free(*a);
        *a = temp;
        (*len_a)++;
        memmove(*b, *b + 1, sizeof(int) * (*len_b - 1));
        (*len_b)--;
        printf("pa\n");
    }
}

void pb(int **a, int *len_a, int **b, int *len_b)
{
    int *temp;
    if (*len_a > 0)
    {
        temp = (int *)malloc(sizeof(int) * (*len_b + 1));
        memcpy(temp + 1, *b, sizeof(int) * (*len_b));
        temp[0] = (*a)[0];
        free(*b);
        *b = temp;
        (*len_b)++;
        memmove(*a, *a + 1, sizeof(int) * (*len_a - 1));
        (*len_a)--;
        printf("pb\n");
    }
}

void ra(int *a, int len_a)
{
    int temp;
    if (len_a > 0)
    {
        temp = a[0];
        memmove(a, a + 1, sizeof(int) * (len_a - 1));
        a[len_a - 1] = temp;
        printf("ra\n");
    }
}

void rb(int *b, int len_b)
{
    int temp;
    if (len_b > 0)
    {
        temp = b[0];
        memmove(b, b + 1, sizeof(int) * (len_b - 1));
        b[len_b - 1] = temp;
        printf("rb\n");
    }
}

void rr(int *a, int len_a, int *b, int len_b)
{
    ra(a, len_a);
    rb(b, len_b);
    printf("rr\n");
}

void rra(int *a, int len_a)
{
    int temp;
    if (len_a > 0)
    {
        temp = a[len_a - 1];
        memmove(a + 1, a, sizeof(int) * (len_a - 1));
        a[0] = temp;
        printf("rra\n");
    }
}

void rrb(int *b, int len_b)
{
    int temp;
    if (len_b > 0)
    {
        temp = b[len_b - 1];
        memmove(b + 1, b, sizeof(int) * (len_b - 1));
        b[0] = temp;
        printf("rrb\n");
    }
}

void rrr(int *a, int len_a, int *b, int len_b)
{
    rra(a, len_a);
    rrb(b, len_b);
    printf("rrr\n");
}
