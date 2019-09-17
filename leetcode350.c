#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int* res = malloc(sizeof(int)*nums1Size);
    int cnt=0,i=0, j=0;
    if(!nums1||!nums2||nums1Size<=0||nums2<=0||!returnSize) {
        *returnSize=0;
        return res;
    }

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    while(i<nums1Size && j<nums2Size) {
        if(nums1[i] == nums2[j]) {
            res[cnt++] = nums1[i];
            i++; j++;
        } else if(nums1[i]<nums2[j]) {
            i++;
        } else j++;
    }

    *returnSize = cnt;
    res = realloc(res, cnt * sizeof(int));

    return res;
}

int main(void) {
    //int nums1[] = {1,2,3,4,5}, nums2[] = {5,6,7,8,9};
    //int nums1[] = {1,2,3,4}, nums2[] = {5,6,7,8};
    //int nums1[] = {9,4,9,8,4}, nums2[] = {4,9,5};
    int nums1[] = {1,2,2,1}, nums2[] = {2,2};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int* result=NULL;
    int retSize;

    result = intersect(nums1, nums1_size, nums2, nums2_size, &retSize);
    if(result==NULL || retSize<=0) {
        printf("result=-1\n");
        return -1;
    }

    for(int i=0; i<retSize; i++) {
        printf("%d ", *(result+i));
    }
    free(result);
    return 0;
}
