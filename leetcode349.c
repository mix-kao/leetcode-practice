#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b );
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1==NULL||nums2==NULL) return NULL;
    int* res = (int*) malloc(sizeof(int)*nums1Size);
    int k=0;
    for(int i=0; i<nums1Size; i++) {
        for(int j=0; j<nums2Size; j++) {
            if(*(nums1+i) == *(nums2+j)) {
                *(res+k) = *(nums1+i);
                k++;
                break;
            }
        }
    }
    *returnSize = k;
    return res;
}

int* intersection1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1==NULL||nums2==NULL) return NULL;
    int* res = (int*) malloc(sizeof(int)*nums1Size);
    int cnt=0;
    for(int i=0; i<nums1Size; i++) {
        if(bsearch((nums1+i), nums2, nums2Size, sizeof(int), compare)!=NULL) {
            if(bsearch((nums1+i), res, cnt, sizeof(int), compare)==NULL) {
                res[cnt++] = nums1[i];
            }
        }
    }
    *returnSize = cnt;
    return res;
}


int main(void) {
    int nums1[] = {1,2,2,1}, nums2[] = {2,2};
    //int nums1[] = {9,4,9,8,4}, nums2[] = {4,9,5};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int* result=NULL;
    int retSize;

    if(nums1_size<nums2_size)
        result = intersection1(nums1, nums1_size, nums2, nums2_size, &retSize);
    else 
        result = intersection1(nums2, nums2_size, nums1, nums1_size, &retSize);
    
    if(result==NULL) return -1;

    for(int i=0; i<retSize; i++) {
        printf("%d ", *(result+i));
    }
    return 0;
}
