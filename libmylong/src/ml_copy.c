#include "../inc/myLong.h"

void ml_copy(t_ml *dst, t_ml *src) {
    for (int i = 0; i < dst->len; i ++) {
        if (src->len <= i)
            break;
        ml_set_block(dst, i, ml_get_block(src, i));
    }
}
