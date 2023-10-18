#include "../inc/myLong.h"

t_mylong *ml_ADD (t_mylong *a, t_mylong *b) {
    t_mylong *c = ml_calloc(a->len);

    unsigned long long carry = 0;
    for (int i = 0; i < c->len; i++) {
        uint32_t val1 = (i < a->len) ? a->arr[i] : 0;
        uint32_t val2 = (i < b->len) ? b->arr[i] : 0;
        carry = 0;
        unsigned long long sum = (unsigned long)val1 + val2 + carry;
        c->arr[i] = (unsigned long long)sum;
        carry = (unsigned long long)(sum >> (BLOCK_SIZE * 4));
    }

    if (carry > 0) {
        // if there is a carry after last block
        t_mylong *res = ml_calloc(c->len + 1);
        ml_copy(res, c);
        res->arr[res->len - 1] = carry;
        t_mylong *temp = c;
        c = res;
        free(temp);
    }

    return c;
}
