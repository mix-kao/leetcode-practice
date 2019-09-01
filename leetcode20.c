#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s){
    int len = strlen(s);
    char stack[len];
    int top=-1;

    while(*s) {
        if(*s == '}') {
            if(top>=0 && stack[top] == '{') top--;
            else return false;
        }
        else if(*s == ']') {
            if(top>=0 && stack[top] == '[') top--;
            else return false;
        }
        else if(*s == ')') {
            if(top>=0 && stack[top] == '(') top--;
            else return false;
        } else {
            stack[++top] = *s;
        }
        s++;
    }
    return top==-1;
}


int main(void) {
    char* str = "[]{[]()}[][]";
    //char* str = "(]";
    if(isValid(str))
        printf("str is validated\n");
    else
        printf("str is not validated\n");
    return 0;
}
