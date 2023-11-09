#include"../inc/myLong.h"

void ml_set_block(t_ml *mylong, int index, unsigned long newValue) {
    switch (mylong->base) {
        case ML_8:
            ((unsigned char *)(mylong->arr))[index] = (unsigned char)newValue;
            break;
        case ML_16:
            ((unsigned short int *)(mylong->arr))[index] = (unsigned short int)newValue;
            break;
        case ML_32:
            ((unsigned long int *)(mylong->arr))[index] = (unsigned long int)newValue;
            break;
        default:
            ml_free(mylong);
            fprintf(stderr, "Error: Unknown base of custom long value.\n");
            exit(0);
    }
    return;
}
