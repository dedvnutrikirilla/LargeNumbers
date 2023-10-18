#include "../inc/myLong.h"

t_mylong *ml_setHex(const char *s) {
    const int slen = strlen(s);
    if (slen == 0) {
        t_mylong *mylong = ml_calloc(1);
        mylong->arr[0] = 0;
        return mylong;
    }

    t_mylong *mylong = ml_calloc(slen / BLOCK_SIZE);
    int block_counter = 0;
    int block_bound_counter = 0;
    for (int i = slen - 1; i >= 0; i--) {
        uint32_t hexValue;
        if (s[i] >= '0' && s[i] <= '9') {
            hexValue = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hexValue = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hexValue = s[i] - 'a' + 10;
        } else {
            fprintf(stderr, "Error: Non-hexadecimal character found.\n");
            ml_free(mylong);
            return NULL;
        }
        mylong->arr[block_counter] += (hexValue << (block_bound_counter * 4));
        // assuming we shift by 4 bits for each hex digit
        //printf("string i position - %d, heVal - %x, block - %x\n", i, hexValue, mylong->arr[block_counter]);
        block_bound_counter++;
        if (block_bound_counter >= BLOCK_SIZE) {
            block_counter++;
            block_bound_counter = 0;
        }
    }

    return mylong;
}

t_mylong *ml_setHex2(const char *s) {
    //convert a string of digits into mylong number
    const int slen = strlen(s);
    if (slen == 0) {
        t_mylong *mylong = ml_calloc(1);
        mylong->arr[0] = 0;
        return mylong;
    }

    t_mylong *mylong = ml_calloc(slen / BLOCK_SIZE);
    int block_counter = 0;
    char *end;
    int i = slen - BLOCK_SIZE;
    
    while(i >= 0) {
        char schunk[9];
        strncpy(schunk, s+i, BLOCK_SIZE);
        mylong->arr[block_counter] = strtoul(schunk, &end, BASE_HEX);
        i-= BLOCK_SIZE;
        block_counter++;
    }

    if (i + BLOCK_SIZE >= 0) {
        char schunk[9];
        strncpy(schunk, s, i+BLOCK_SIZE);
        mylong->arr[block_counter] = strtoul(schunk, &end, BASE_HEX);
    }

    return mylong;
}
