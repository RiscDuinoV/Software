#include "sum.h"

int sum(int *ptr, int len)
{
    int i;
    int ret_sum = 0;
    for (i = 0; i < len; i++)
    {
        ret_sum += ptr[i];
    }
    return ret_sum;
}