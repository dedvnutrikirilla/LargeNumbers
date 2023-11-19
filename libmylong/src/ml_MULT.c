#include "../inc/myLong.h"

t_ml *ml_MULT (t_ml *a, t_ml *b) {
    t_ml *c = ml_calloc(a->base, 1);
    if ((a->len == 1 && !ml_get_block(a, 0))
    || (b->len == 1 && !ml_get_block(b, 0)))
        return c;
    //
    for (int i = 0; i < a->len; i ++) {
        unsigned long long block_a = ml_get_block(a, i);
        for (int j = 0; j < b->len; j++) {
            unsigned long long block_b = ml_get_block(b, j);
            unsigned long long prod = block_a * block_b;
            unsigned long block_c1 = prod,
            block_c2 = prod >> c->base;
            t_ml *temp_1 = ml_calloc(c->base, c->base * 2);
            ml_set_block(temp_1, 0, block_c1);
            ml_set_block(temp_1, 1, block_c2);
            t_ml *temp_2 = ml_shiftL(temp_1, (i + j) * a->base);
            t_ml *temp_3 = ml_ADD(c, temp_2);
            // printf("\nblock_a:\t%llx\nblock_b:\t%llx\nprod:\t%llx\nblock_c1:\t%lx\nblock_c2:\t%lx\n", block_a, block_b, prod, block_c1, block_c2);
            // printf("temp1:\n");
            // ml_outBlocked(temp_1);
            // printf("temp2:\n");
            // ml_outBlocked(temp_2);
            // printf("c:\n");
            // ml_outBlocked(c);
            // printf("temp3:\n");
            // ml_outBlocked(temp_3);
            ml_free(temp_1);
            ml_free(temp_2);
            ml_free(c);
            c = temp_3;
            // printf("c:\n");
            // ml_outBlocked(c);
        }
    }
    return c;
}
