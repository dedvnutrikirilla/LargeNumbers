#include "../inc/myLong.h"

t_mylong *ml_dup(t_mylong *ml) {
    t_mylong *newml = ml_calloc(ml->len);
    ml_copy(newml, ml);
    return newml;
}
