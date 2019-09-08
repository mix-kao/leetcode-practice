#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isPalindrome(char* str) {
    if(str==NULL) {
        printf("str is NULL!");
        return;
    }
    int l=0;
    int h=strlen(str)-1;

    while(h>l) {
        //printf("%c %c \n", str[l], str[h]);
        if(str[l++]!=str[h--]) {
            printf("Not the same.");
            return;
        }
    }
    printf("Is same!");

}

int main(void) {
    //char* str = "ABCDEFGHIJK";
    //char* str = "ABCDCBA";
    char* str = NULL;
    isPalindrome(str);
    return 0;
}
