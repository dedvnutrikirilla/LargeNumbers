#include"../inc/myLong.h"

t_ml *ml_setHex(t_ml_base base, char *s) {
    const size_t slen = strlen(s);
    if (slen == 0) {
        t_ml *mylong = ml_calloc(ML_8, 1);
        ((unsigned char *)(mylong->arr))[0] = 0;
        return mylong;
    }
    
    t_ml *mylong = ml_calloc(base, slen * 4); // it takes 4 bits to store any hex digit

    unsigned short block_bound = 0, block_cur = 0;

    for (int i = slen - 1; i >= 0; i--) {
        unsigned long hexVal; // 4 bits
        if (s[i] >= '0' && s[i] <= '9') {
            hexVal = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hexVal = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hexVal = s[i] - 'a' + 10;
        } else {
            fprintf(stderr, "Error: Non-hexadecimal character found.\n");
            ml_free(mylong);
            return NULL;
        }

        ml_set_block(mylong, block_cur, ml_get_block(mylong, block_cur) | ((hexVal << block_bound)));
        block_bound += 4;
        if (block_bound >= mylong->base) {
            block_bound = 0;
            block_cur++;
        }
    }

    return mylong;
}
