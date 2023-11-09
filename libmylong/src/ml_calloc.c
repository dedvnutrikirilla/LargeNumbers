#include"../inc/myLong.h"

t_ml *ml_calloc(t_ml_base base, int nbits) {
    t_ml *mylong = (t_ml *)malloc(sizeof(t_ml));
    if (!mylong)
        return NULL;
    mylong->len = (nbits + base - 1) / base; // (+ base - 1) in case (nbits/base) has a remainder
    mylong->base = base;

    switch (mylong->base) {
        case ML_8:
            mylong->arr = malloc(mylong->len * sizeof(unsigned char));
            break;
        case ML_16:
            mylong->arr = malloc(mylong->len * sizeof(unsigned short int));
            break;
        case ML_32:
            mylong->arr = malloc(mylong->len * sizeof(unsigned long int));
            break;
        default:
            free(mylong);
            return NULL;
    }

    if (!mylong->arr) {
        free(mylong);
        return NULL;
    }
        
    for (int i = 0; i < mylong->len; i++) {
        ml_set_block(mylong, i, 0);
    }
    return mylong;
}
