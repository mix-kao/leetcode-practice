#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x==0) return true;
    if(x%10==0) return false;
    int result=0;
    while(x>result) {
        result = result * 10 + x%10;
        x/=10;
    }

    return (result==x||result/10==x);
}

int main(void) {
    int x = 122;
    bool res = isPalindrome(x);
    if(res) printf("OK"); else printf("FAIL");
    return 0;
}
