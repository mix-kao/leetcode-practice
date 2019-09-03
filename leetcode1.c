#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i=0; i<numsSize; i++) {
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i]+nums[j]==target) {
                *returnSize=2;
                int *result=(int*)malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main(void) {
    int data[] = {2, 7, 11, 15};
    int target = 9;
    int data_size = sizeof(data)/sizeof(data[0]);
    int returnSize=0;
    int* ret = twoSum(data, data_size, target, &returnSize);
    if(ret) {
        for(int i=0; i<returnSize; i++)
            printf("%d ", *(ret+i));
    }
    return 0;
}
