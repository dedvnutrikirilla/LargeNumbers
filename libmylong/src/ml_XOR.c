#include "../inc/myLong.h"

t_mylong *ml_XOR(t_mylong *a, t_mylong *b) {
    int maxlen = a->len > b->len ? a->len : b->len;
    t_mylong *c = ml_calloc(maxlen);

    for (int i = 0; i < c->len; i++) {
        if(a->len < i)
            c->arr[i] = b->arr[i] ^ 0;
        else if (b->len < i)
            c->arr[i] = a->arr[i] ^ 0;  
        else {
            c->arr[i] = a->arr[i] ^ b->arr[i];
            //printf("%x XOR %x = %x\n", a->arr[i], b->arr[i], c->arr[i]);
        }
    }
    return c;
}
