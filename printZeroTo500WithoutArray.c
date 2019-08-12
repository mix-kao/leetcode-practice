#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
題目會給一個int a[20]已排序的陣列，
請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素，
請用最少的時間和空間複雜度完成。
*/
void print0to500(int a[], size_t a_size) {
    int match = 0;
    for(int i=0; i<=500; i++) {
        match = 0;
        for(int j=0; j<a_size; j++) {
            if(i == a[j]) {match=1; break;}
        }
        if(!match) printf("%d ", i);
    }
}


int main(void) {
    
    int a[] = {1, 2, 3, 4, 5, 10};
    size_t a_size = sizeof(a)/sizeof(a[0]);

    print0to500(a, a_size);

    return 0;
}
