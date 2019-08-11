#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 256

int input[] = {15678, 15688, 1234567};
char units[4][10] = {"", "thousand", "million", "billion"};
char all_string[STR_LEN] = {0};
char string[STR_LEN] = {0};
char string1[STR_LEN] = {0};

char* getStr(int num) {
    switch(num) {
        case 0: return "";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirdteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 30: return "thirdty";
        case 40: return "fourty";
        case 50: return "fifty";
        case 60: return "sixty";
        case 70: return "seventy";
        case 80: return "eighty";
        case 90: return "ninety";
        case 100: return "hundred";
        default: return "";
    }
}

/* convert number < 1000 */
char* convert(int num) {
    memset(string, 0, STR_LEN);
    memset(string1, 0, STR_LEN);
    if(num>=100) {
        sprintf(string1, " %s ", convert(num%100));
        sprintf(string, " %s %s %s ", getStr(num/100), getStr(100), string1);
        return string;
    } else if(num>20) {
        sprintf(string, " %s %s %s ", getStr((num/10)*10), getStr(0), getStr(num%10));
        return string;
    } else if(num>10) {
        return getStr(num);
    } else if(num>0) {
        return getStr(num);
    }
}

char* numberToWords(int num) {
    int i=0, j=0, n=0;
    char temp[STR_LEN] = {0};
    memset(all_string, 0, STR_LEN);
    memset(temp, 0, STR_LEN);
    while(num>0) {
        n = num%1000;
        if(n > 0) {
            if(j>0) {
                strcpy(temp, all_string);
            }
            sprintf(all_string, " %s %s ", convert(n), units[i]);
            if(j>0) {
                strcat(all_string, temp);
            }
            j++;
        }
        i++;
        num/=1000;
    }
    return all_string;

}


int main(void) {
    char* ptr = NULL;
    size_t input_num = sizeof(input)/sizeof(int);

    printf("sizeof input = %ld\n", input_num);

    for(int i=0; i<input_num; i++) {
        printf("input[%d] = %d\n", i, input[i]);
        ptr = numberToWords(input[i]);
        printf("\n\n\n\n\nresult is %s \n", ptr);
    }
    return 0;
}
