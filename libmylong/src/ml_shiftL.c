#include "../inc/myLong.h"

t_mylong *ml_shiftL (t_mylong *ml, int n) {
    if(n >= BLOCK_SIZE || n < 0) {
        perror("\nERROR: invalid shift value!\n");
        return NULL;
    }
    t_mylong *newml = ml_calloc(ml->len + 1);

    for (int i = 0; i < newml->len; i++) {
        if (ml->len <= i)
            newml->arr[i] = 0;
        else
            newml->arr[i] = ml->arr[i] << n;          
        if (i > 0) {
            uint32_t carry = (ml->arr[i - 1] >> ((BLOCK_SIZE - n)*4)); 
            newml->arr[i] |= carry;
            //printf("carry shift newml | %x = %x\n", carry, newml->arr[i]);
        } 
    }
    return newml;
}
