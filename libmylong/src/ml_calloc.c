#include "../inc/myLong.h"

t_mylong *ml_calloc(int nblocks) {
    t_mylong *mylong = (t_mylong *)malloc(sizeof(t_mylong));
    if (!mylong)
        return NULL;
    mylong->len = nblocks;
    mylong->arr = (uint32_t *)malloc(mylong->len * sizeof(uint32_t));
    if (!mylong->arr) {
        free(mylong);
        return NULL;
    }
        
    for (int i = 0; i < mylong->len; i++) {
        mylong->arr[i] = 0;
    }
    return mylong;
}
