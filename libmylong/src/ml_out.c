#include"../inc/myLong.h"

/*static inline void ml_putzeros(int n) {
    while (n >= 0 ) {
        putchar('0');
        n--;
    }
}*/

void ml_test_out_blockBits (unsigned long long block, unsigned char block_size) {
    for (int j = block_size - 1; j >= 0; j--) {
        putchar(((block >> j) & 1) ? '1' : '0');
    }
}

static inline void ml_out_blockBits(unsigned long block, t_ml_base block_size) {
    for (int j = block_size - 1; j >= 0; j--) {
        putchar(((block >> j) & 1) ? '1' : '0');
    }
}

void ml_outBits(t_ml *mylong, int isBlocked) {
    if (!isBlocked) {
        putchar('0');
        putchar('b');
    }
    
    for (int i = mylong->len - 1; i >= 0; i--) {
        if (isBlocked) {
            putchar('0');
            putchar('b');
        }
        unsigned long block = ml_get_block(mylong, i);
        ml_out_blockBits(block, mylong->base);
        if (isBlocked) putchar('\n');
    }
    if (!isBlocked) putchar('\n');
    return;
}

void ml_outBlocked(t_ml *mylong) {  
    switch (mylong->base) {
        case ML_8:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%x\n", ((unsigned char *)mylong->arr)[i]);
            break;
        case ML_16:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%x\n", ((unsigned short *)mylong->arr)[i]);
            break;
        case ML_32:
            for(int i = mylong->len -1; i >= 0; i--)
                printf("%lx\n", ((unsigned long *)mylong->arr)[i]);
            break;
        default:
            ml_free(mylong);
            fprintf(stderr, "Error: Unknown base of custom long value.\n");
            exit(0);
    }
    printf("\n");
}
