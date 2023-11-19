#include "../inc/myLong.h"

t_ml *ml_shiftL (t_ml *a, unsigned int n) {
    int overclock = 0, overhead = 0;
    unsigned long long carry = 0ULL,
    block = ml_get_block(a, a->len - 1);
    if (n >= a->base) {
        overclock = n / a->base;
        n = n % a->base;
    }
    if ((block << n) & (0xFFFFFFFFFFFFFFFF << a->base))
        overhead = 1;
    t_ml *c = ml_calloc(a->base, a->base * (a->len + overhead + overclock));

    for(int i = overclock; i < c->len; i++) {
        // printf("\nblock:\t%d\ncarry:\t", i);
        // ml_test_out_blockBits(carry, 64);
        // printf("\nblock:\t");
        // ml_test_out_blockBits(ml_get_block(a, i - overclock), 64);
        block = (unsigned long long)(ml_get_block(a, i - overclock));
        unsigned long long val = i - overclock >= a->len ? carry : (block << n) | carry;
        carry = (val & (0xFFFFFFFFFFFFFFFF << c->base)) >> c->base;
        // printf("\nval:\t");
        // ml_test_out_blockBits(val, 64);
        // printf("\ncarry:\t");
        // ml_test_out_blockBits(carry, 64);
        // printf("\n");
        ml_set_block(c, i, (unsigned long)val);
    }

    return c;
}
