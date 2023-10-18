#include "../inc/myLong.h"

char *ml_getHex(t_mylong *mylong) {
    const int maxlen = BLOCK_SIZE * mylong->len;
    char *out = (char *)malloc(sizeof(char) * maxlen);

    char temp[sizeof(uint32_t)*8+1];
    int offset = 0;
    for (int i = mylong->len - 1; i >= 0; i--) {
        sprintf(temp, "%x", mylong->arr[i]);
        strcpy(out + offset, temp);
        offset += strlen(temp);
        //printf("i - %d, %s\n", i, temp);
    }

    return out;
}
