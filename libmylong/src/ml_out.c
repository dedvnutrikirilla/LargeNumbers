#include "../inc/myLong.h"

void ml_out(t_mylong *mylong) {
    for(int i = mylong->len -1; i >= 0; i--) {
        printf("%x", mylong->arr[i]);
    }
    printf("\n");
}
