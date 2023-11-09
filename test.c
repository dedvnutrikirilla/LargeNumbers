#include"./libmylong/inc/myLong.h"

int main() {
    t_ml *a = ml_setHex(32, "FFFFFFF");
    t_ml *b = ml_setHex(32, "FFFFFFF");

    t_ml *s = ml_ADD(a, b);
    //printf("\n%lld\n", sizeof(int));
    ml_out(s);

}
