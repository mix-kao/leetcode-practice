#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x<0) return false;
    if(!x) return true;
    int before=x, result=0;
    while(x) {
        result = result * 10 + x%10;
        x = x/10;
    }
    return (before == result);
}

int main(void) {
    int x = 121;
    if(isPalindrome(x)) printf("OK"); else printf("FAIL");
    return 0;
}
