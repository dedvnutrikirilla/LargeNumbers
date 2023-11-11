#include "../inc/myLong.h"

t_ml *ml_XOR(t_ml *a, t_ml *b) {
    t_ml *c = ml_calloc(a->base, a->base * (a->len > b->len ? a->len : b->len));

    for (int i = 0; i < c->len; i++) {
        if(a->len < i)
            ml_set_block(c, i, ml_get_block(b, i) ^ 0);
        else if (b->len < i)
            ml_set_block(c, i, ml_get_block(a, i) ^ 0); 
        else
            ml_set_block(c, i, ml_get_block(a, i) ^ ml_get_block(b, i)); 
    }
    return c;
}