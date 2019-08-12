#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
題目會給一個int a[20]已排序的陣列，
請寫一個function(a, size, b)能依照參數b(b = 0~4)別印出該區間的數字，
且不包含a陣列內的元素，
例如：
　b = 0, 印出0~99
　b = 1, 印出100~199

  b*100 ~ (b+1)*100
　...
請用最少的時間和空間複雜度完成。
*/

void printRange(int* a, size_t a_size, int b) {
    int* nextPtr = a;
    //依照b設定符合a[]的範圍
    while(*nextPtr < b*100){
        nextPtr++;
    }

    for(int i=b*100; i<(b+1)*100; i++) {
        if(i == *nextPtr) nextPtr++;
        else {
            printf("%d ", i);
        }
        if(i%10==0) printf("\n");
    }
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 10, 40, 50, 60, 150, 250, 350, 450, 499};
    size_t a_size = sizeof(a)/sizeof(a[0]);
    printRange(a, a_size, 0);
    return 0;
}
