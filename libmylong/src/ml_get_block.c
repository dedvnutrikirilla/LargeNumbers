#include"../inc/myLong.h"

unsigned long ml_get_block(t_ml *mylong, int index) {
    switch (mylong->base) {
        case ML_8:
            return (unsigned long) ((unsigned char *)(mylong->arr))[index];
            break;
        case ML_16:
            return (unsigned long) ((unsigned short int *)(mylong->arr))[index];
            break;
        case ML_32:
            return (unsigned long) ((unsigned long int *)(mylong->arr))[index];
            break;
        default:
            ml_free(mylong);
            fprintf(stderr, "Error: Unknown base of custom long value.\n");
            exit(0);
    }
}
