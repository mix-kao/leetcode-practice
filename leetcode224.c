#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(char* str) {
    int len = strlen(str);
    int sign=1, num=0, res=0;
    int* stack = malloc(sizeof(int)*len);
    int top=0;

    for(int i=0; i<len; i++) {
        char c = *(str+i);
        if (c >= '0') {
            num = 10 * num + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            stack[top++] = res;
            stack[top++] = sign;
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            res *= stack[--top];
            res += stack[--top];
        }
    }

    for(int k=len-1; k>=0; k--) {
        if(stack[k]!=0)
        printf("stack[%d] = %d\n", k, stack[k]);
    }

    free(stack);
    return res += sign * num;

}

int main(void) {
    char* s= "300  + (100 - 100) +100 ";
    printf("result = %d \n", calculate(s));
    return 0;
}
