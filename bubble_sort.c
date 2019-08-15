#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int unsorted[] = {23, 53, 10, 234, 2, 12};

int main(void) {
    int ary_size = sizeof(unsorted)/sizeof(unsorted[0]);
    int temp, i;
    for(i=0;i<ary_size;i++) {
        printf("%d ", unsorted[i]);
    }
    for(int k=ary_size-1; k>=0; k--) {
        for(int j=0;j<k;j++) {
            if(unsorted[j] > unsorted[j+1]) {
                temp = unsorted[j+1];
                unsorted[j+1] = unsorted[j];
                unsorted[j] = temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<ary_size;i++) {
        printf("%d ", unsorted[i]);
    }
    return 0;
}
