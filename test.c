#include"./libmylong/inc/myLong.h"

int main() {
    t_ml *a = ml_setHex(16, "197F000158BF");
    t_ml *b = ml_setHex(16, "AFBB0000892B");

    ml_out(a);
    ml_out(b);


    
    t_ml *s1 = ml_DIFF(b, a);
    ml_out(s1);
    ml_free(s1);
    // t_ml *s2 = ml_OR(a, b);
    // ml_out(s2);
    // ml_free(s2);
    // t_ml *s3 = ml_XOR(a, b);
    // ml_out(s3);
    // ml_free(s3);
    // t_ml *s4 = ml_INV(a);
    // ml_out(s4);
    // ml_free(s4);
    // t_ml *s5 = ml_ADD(a, b);
    // ml_out(s5);
    // ml_free(s5);

    ml_free(a);
    ml_free(b);
    
}
