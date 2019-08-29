#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrCpy(char* dst , char* src) {
    while(*(src)) {
        *(dst++) = *(src++);
    }
}

int main(void) {
    char* str = "123456789";
    char dst[32] = {0};
    StrCpy(dst, str);
    printf("dst=%s\n", dst);
    return 0;
}
