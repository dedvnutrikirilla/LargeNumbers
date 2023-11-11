#include "../inc/myLong.h"

t_ml *ml_INV(t_ml *a) {
    t_ml *c = ml_calloc(a->base, a->base * a->len);

    for (int i = 0; i < c->len; i++) {
        ml_set_block(c, i , ~ml_get_block(a, i));
    }

    return c;
}
