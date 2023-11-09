#include"../inc/myLong.h"

void ml_free(t_ml *mylong) {
    free(mylong->arr);
    free(mylong);
    return;
}
