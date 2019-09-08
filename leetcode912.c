#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* retAry = malloc(sizeof(int)*numsSize);
    int k=0;
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i=0; i<numsSize; i++) {
        *(retAry+i) = *(nums+i);
        k++;
    }
    *(returnSize)=k;
    return retAry;
}

int main(void) {
    int data[] = {55, 33, 44, 123, 43, 21, 19, 0, 484, 322, 1234};
    int size = sizeof(data)/sizeof(data[0]);
    int retSize=0;
    int* result=NULL;
    result = sortArray(data, size, &retSize);
    printf("retSize = %d \n", retSize);
    for(int i=0; i<retSize; i++) {
        printf("%d ", *(result+i));
    }
    return 0;
}
