#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int strLen(const char *str) {
    int len = 0;
    while(*(str++)) {
        len++;
    }
    return len;
}

int main(void) {
    char* str = "123456789";
    int len = strLen(str);
    printf("len=%d\n", len);
    return 0;
}
