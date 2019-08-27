#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char  aFile[] = "./aaaaa";
    char* bFile = "./bbbbb";
    int ret=0;
    FILE *afp, *bfp;
    char ch[100] = {0};

    if(NULL == (afp=fopen(aFile, "r"))) {
        printf("Open %s fail", aFile);
        ret = 1;
    }
    if(NULL == (bfp=fopen(bFile, "w"))) {
        printf("Open %s fail", bFile);
        ret = 1;
    }
    while(!feof(afp)) {
        size_t size = fread(ch, sizeof(char), 100, afp);
        fwrite(ch, sizeof(char), size, bfp);
    }
    fclose(afp);
    fclose(bfp);

    return ret;
}
