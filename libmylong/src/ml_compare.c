#include "../inc/myLong.h"

// We compare longs asuming that they all have correct structure
// 1) no empty blocks in the beginning
// 2) only positive numbers
// 3) same base
//
// Returns: 
// 1 if a > b
// 0 if 1 == b
// -1 if a < b

int ml_compare(t_ml *a, t_ml *b) {
    if (a->len > b->len)
        return 1;
    else if (a->len < b->len)
        return -1;
    // malongs have same length, check blocks starting from the left side of the number
    for (int i = a->len -1; i >= 0; i--) {
        unsigned long block_a = ml_get_block(a, i);
        unsigned long block_b = ml_get_block(b, i);

        if (block_a > block_b)
            return 1;
        else if (block_a < block_b)
            return -1;
    }

    return 0;
}
