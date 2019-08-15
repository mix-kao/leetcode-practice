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

    for(int k=0; k<ary_size-1; k++) {
        for(int j=k+1;j<ary_size;j++) {
            if(unsorted[k] > unsorted[j]) {
                temp = unsorted[j];
                unsorted[j] = unsorted[k];
                unsorted[k] = temp;
            }
        }
    }

    printf("\n");
    for(i=0;i<ary_size;i++) {
        printf("%d ", unsorted[i]);
    }
    return 0;
}
