#include "../inc/myLong.h"

#include "math.h"

t_ml *ml_DIFF (t_ml *a, t_ml *b) {
    int comp = ml_compare(a, b);
    if (comp == 0)
        return ml_calloc(a->base, 1);
    else if (comp < 0)
        return NULL;
    // for now logic works only if a > b

    const int len = a->len;
    t_ml *c = ml_calloc(a->base, len * a->base);

    unsigned long long carry = 0ULL, val_a, val_b, diff; 
    for (int i = 0; i < len; i++) {
        val_a = (i < a->len) ? ml_get_block(a, i) : 0ULL; // if a > b statement always goes for ml_get_block
        val_b = (i < b->len) ? ml_get_block(b, i) : 0ULL;

        val_b += carry;
        carry = 0ULL;

        if (val_a < val_b) {
            val_a += (1ULL << a->base);
            carry = 1ULL;
        }
        diff = val_a - val_b;
        ml_set_block(c, i, diff);
    }

    return c;
}
