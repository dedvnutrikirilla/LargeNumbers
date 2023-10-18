#include "../inc/myLong.h"

t_mylong *ml_copy(t_mylong *dst, t_mylong *src) {       
    for (int i = 0; i < dst->len; i++) {
        if (src->len <= i)
            dst->arr[i] = 0;
        else
            dst->arr[i] = src->arr[i];
    }
    return dst;
}
