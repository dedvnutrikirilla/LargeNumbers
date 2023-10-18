// For easier testing and debugging dont archive libs for now
#include "./libmylong/inc/myLong.h"

int main() {
    t_mylong *a = ml_setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
    t_mylong *b = ml_setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
    ml_out(a);
    ml_out(b);

    t_mylong *res_xor = ml_XOR(a, b);
    ml_outBlocked(res_xor);
    ml_out(res_xor);
    char *hex_string = ml_getHex(res_xor);
    printf("%s\n", hex_string);

    ml_free(a);
    ml_free(b);
    ml_free(res_xor);
    free(hex_string);

    t_mylong *a2 = ml_setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
    t_mylong *b2 = ml_setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
    ml_out(a2);
    ml_out(b2);
    t_mylong *res_sum =  ml_ADD(a2, b2);
    ml_out(res_sum);

    ml_free(a2);
    ml_free(b2);
    ml_free(res_sum);
    return 0;
}
