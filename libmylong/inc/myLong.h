#ifndef MALONG_H
#define MALONG_H

// Definers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
//
#define BLOCK_SIZE 8
#define BASE_HEX 16
//#define BASE_DEC 10
// Ma long unsigned itself
typedef struct s_mylong {
    uint32_t *arr; // array of uint32_t blocks
    int len; // number of blocks
} t_mylong;
//

// get/set
char *ml_getHex(t_mylong *mylong);
t_mylong *ml_setHex(const char *s);
t_mylong *ml_setHex2(const char *s);
//

//utils
t_mylong *ml_calloc(int nblocks);
t_mylong *ml_copy(t_mylong *dst, t_mylong *src);
t_mylong *ml_dup(t_mylong *ml);
void ml_free(t_mylong *mylong);
void ml_out(t_mylong *mylong);
void ml_outBlocked(t_mylong *mylong);
//

//biwise
t_mylong *ml_INV(t_mylong *ml);
t_mylong *ml_XOR(t_mylong *a, t_mylong *b);
t_mylong *ml_OR(t_mylong *a, t_mylong *b);
t_mylong *ml_AND(t_mylong *a, t_mylong *b);
t_mylong *ml_shiftR (t_mylong *ml, int n);
t_mylong *ml_shiftL (t_mylong *ml, int n);
//

// 
t_mylong *ml_ADD (t_mylong *a, t_mylong *b);
//
#endif
