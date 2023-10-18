#include "../inc/myLong.h"

void ml_free(t_mylong *mylong) {
    free(mylong->arr);
    free(mylong);
    return;
}
