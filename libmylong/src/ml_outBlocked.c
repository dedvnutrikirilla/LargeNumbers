#include "../inc/myLong.h"

void ml_outBlocked(t_mylong *mylong) {
    printf("mylong:\n");
    for(int i = 0; i < mylong->len; i++) {
        printf("%d - block: [%x]\n",i , mylong->arr[i]);
    }
    printf("\n");
}
