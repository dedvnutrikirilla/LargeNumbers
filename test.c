#include"./libmylong/inc/myLong.h"

int main() {
    t_ml *a = ml_setHex(32, "7d7deab2affa38154326e96d350deee1");
    t_ml *b = ml_setHex(32, "97f92a75b3faf8939e8e98b96476fd22");

    ml_outBits(a, 1);
    ml_outBlocked(a);
    putchar('\n');
    ml_outBits(b, 1);
    ml_outBlocked(b);
    putchar('\n');
    t_ml *s1 = ml_MULT(a, b);
    ml_outBits(s1, 1);
    ml_outBlocked(s1);
    ml_free(s1);

    ml_free(a);
    ml_free(b);
}
