#include"../inc/myLong.h"

void ml_out(t_ml *mylong) {
    switch (mylong->base) {
        case ML_8:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%x\n", ((unsigned char *)mylong->arr)[i]);
            break;
        case ML_16:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%x\n", ((unsigned short *)mylong->arr)[i]);
            break;
        case ML_32:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%lx\n", ((unsigned long *)mylong->arr)[i]);
            break;
        default:
            ml_free(mylong);
            fprintf(stderr, "Error: Unknown base of custom long value.\n");
            exit(0);
    }
    printf("\n");
}
