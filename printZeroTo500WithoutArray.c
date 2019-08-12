#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
題目會給一個int a[20]已排序的陣列，
請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素，
請用最少的時間和空間複雜度完成。
*/
void print0to500(int* a, size_t a_size) {
    for(int i=0; i<=500; i++) {
        if(i == *a) a++;
        else {
            printf("%d ", i);
            if((i%10)==0) printf("\n");
        }
    }
}


int main(void) {
    int a[] = {1, 2, 3, 4, 5, 10, 40, 50, 60, 150, 250, 350, 450, 499};
    size_t a_size = sizeof(a)/sizeof(a[0]);
    print0to500(a, a_size);
    return 0;
}
