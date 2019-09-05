#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int a[] = {9,1,4,3,2,1,123,22,45,88};
    int Max = a[0], Min = a[0], Avg = 0;
    int a_size = sizeof(a)/sizeof(a[0]);
    printf("max=%d, min=%d, avg=%d\n", Max, Min, Avg);
    for(int i=0 ; i < a_size ; i++) {
        if(Min > a[i]) Min = a[i];
        if(Max < a[i]) Max = a[i];
        Avg += a[i];
        printf("a[%d]=%d, max=%d, min=%d, avg=%d\n", i, a[i], Max, Min, Avg);
    }
    printf("max=%d, min=%d, avg=%d\n", Max, Min, Avg/a_size);
    return 0;
}
