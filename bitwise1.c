#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_highest_bit_order(unsigned x){
    int n = 31;
    if(x == 0) return -1;
    if(x>>16 == 0) {n = n-16; x = x << 16;}
    if(x>>24 == 0) {n = n-8; x = x << 8;}
    if(x>>28 == 0) {n = n-4; x = x << 4;}
    if(x>>30 == 0) {n = n-2; x = x << 2;}
    if(x>>31 == 0) {n = n-1; x = x << 1;}
    return n;
}

int main(void) {

    unsigned x1 = 0x80000000; // = 0b1000 0000 0000 0000 0000 0000 0000 0000
    unsigned x2 = 0x00000001; // = 0b0000 0000 0000 0000 0000 0000 0000 0001

    printf("%d \n", get_highest_bit_order(x1));  // 31
    printf("%d \n", get_highest_bit_order(x2));  // 0

    return 0;
}
