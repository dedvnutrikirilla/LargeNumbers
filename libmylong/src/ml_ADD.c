#include "../inc/myLong.h"

t_ml *ml_ADD (t_ml *a, t_ml *b) {
    const int len = a->len;
    t_ml *c = ml_calloc(a->base, a->len * a->base);

    unsigned long long carry = 0ULL, val_a, val_b, sum; 
    for (int i = 0; i < len; i++) {
        val_a = (i < a->len) ? ml_get_block(a, i) : 0ULL;
        val_b = (i < b->len) ? ml_get_block(b, i) : 0ULL;

        sum = val_a + val_b + carry;
        ml_set_block(c, i, sum);
        carry = sum >> a->base;
        //printf("a=%llx; b= %llx\tsum=%llx; carry=%llx; carry=%u;\n", val_a, val_b, sum, carry, a->base);
    }

    if (carry > 0) {
        t_ml *new_c = ml_calloc(c->base, (c->len * c->base) + 1);
        ml_copy(new_c, c);
        ml_set_block(new_c, len, carry);
        ml_free(c);
        return new_c;
    }
    return c;
}
