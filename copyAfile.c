#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *read, *write;
    char* r_filePath="./aaa";
    char* w_filePath="./bbb";
    char buf;
    if(NULL == (read  = fopen(r_filePath, "r"))) return 1;
    if(NULL == (write = fopen(w_filePath, "w"))) return 1;
    while(!feof(read)) {
        fread(&buf, sizeof(char), 1, read);
        fwrite(&buf, sizeof(char), 1, write);
    }
    fclose(read);
    fclose(write);
    return 0;
}
