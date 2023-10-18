#include "../inc/myLong.h"

t_mylong *ml_shiftR (t_mylong *ml, int n) {
    if(n >= BLOCK_SIZE || n < 0) {
        perror("\nERROR: invalid shift value!\n");
        return NULL;
    }
    t_mylong *newml = ml_calloc(ml->len);

    for (int i = 0; i < newml->len; i++) {
        newml->arr[i] = ml->arr[i] >> n;
        if (i + 1 < newml->len) {
            newml->arr[i] |= (ml->arr[i + 1] << ((BLOCK_SIZE - n)*4));
        }
    }
    return newml;
}
