#include "../inc/myLong.h"

t_mylong *ml_INV(t_mylong *ml) {
    t_mylong *newml = ml_dup(ml);

    for (int i = newml->len - 1; i >= 0; i--) {
        newml->arr[i] = ~ml->arr[i];
    }
    return newml;
}
