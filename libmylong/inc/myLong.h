#ifndef MALONG_H
#define MALONG_H

// Definers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
// Ma long type/base enum
typedef enum e_ml_base{
    ML_8 = 8,   // unsigned char
    ML_16 = 16, // unsigned short
    ML_32 = 32  // unsigned long
} t_ml_base;
// Ma long unsigned itself
typedef struct {
    void *arr;      // Pointer to the array
    int len;        // Number of blocks
    t_ml_base base; // Data type/base
} t_ml;
//

// get/set
// char *ml_getHex(t_ml *mylong, char *s);
t_ml *ml_setHex(t_ml_base base, char *s);
//

//utils
void ml_free(t_ml *mylong);
void ml_out(t_ml *mylong);
t_ml *ml_calloc(t_ml_base base, int nbits);
void ml_copy(t_ml *dst, t_ml *src);
int ml_compare(t_ml *a, t_ml *b);
//

// Shitty block operations
void ml_set_block(t_ml *mylong, int index, unsigned long newValue);
unsigned long ml_get_block(t_ml *mylong, int index);
/*
typedef void (*OperationFunc)(void *Op, int index, unsigned long value);
void ml_setOR_block8(void *arr, int index, unsigned long value);
void ml_setOR_block16(void *arr, int index, unsigned long value);
void ml_setOR_block32(void *arr, int index, unsigned long value);
*/
//
//Bitwises
t_ml *ml_AND(t_ml *a, t_ml *b);
t_ml *ml_OR(t_ml *a, t_ml *b);
t_ml *ml_XOR(t_ml *a, t_ml *b);
t_ml *ml_INV(t_ml *a);
//

// Arithms
t_ml *ml_ADD(t_ml *a, t_ml *b);
t_ml *ml_DIFF(t_ml *a, t_ml *b);
//
#endif
