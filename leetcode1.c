#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cnt=0;

int* m1_loop(int* nums, int numsSize, int target, int* retSize) {
    for(int i=0; i<numsSize; i++) {
        for(int j=i+1; j<numsSize; j++) {
            cnt++;
            if(nums[i]+nums[j] == target) {
                int* ret = (int*) malloc(sizeof(int)*2);
                if(ret==NULL) return NULL;
                else {
                    ret[0] = i;
                    ret[1] = j;
                    *retSize=2;
                    return ret;
                }
            }
        }
    }
    return NULL;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* m2_sort(int* nums, int numsSize, int target, int* retSize) {
    bool checked = false;
    int* temp_ary = (int*)malloc(sizeof(int)*numsSize);
    if(temp_ary==NULL) return NULL;
    for(int i=0; i<numsSize; i++) {
        *(temp_ary+i) = *(nums+i);
    }
    qsort(temp_ary, numsSize, sizeof(int), compare);

    int start=0, end=numsSize-1;
    while(start<end) {
        cnt++;
        if(temp_ary[start]+temp_ary[end] == target) {checked=true; break;}
        else if(temp_ary[start]+temp_ary[end] < target) start++;
        else end--;
    }
    if(checked) {
        int* ret = (int*) malloc(sizeof(int)*2);
        if(ret==NULL) return NULL;
        else {
            int index=0;
            for(int i=0; i<numsSize; i++) {
                if(nums[i] == temp_ary[start] || nums[i] == temp_ary[end]) {
                    ret[index++] = i;
                }
            }
            *retSize=2;
            return ret;
        }
    }

    return NULL;
}

int main(void) {
    //int data[] = {1, 15, 14, 13, 12, 6, 5, 4, 3, 2, 1};
    int data[] = {3, 2, 4};
    int target = 6, retSize;
    int size = sizeof(data)/sizeof(data[0]);
    int* ret = m1_loop(data, size, target, &retSize);
    if(ret==NULL) {
        printf("Can't not find...\ncount=%d\n", cnt);
    }
    else {
        for(int i=0; i<retSize; i++) {
            printf("ret[%d] = %d, count = %d\n", i, ret[i], cnt);
        }
    }
    cnt=0;
    int* ret1 = m2_sort(data, size, target, &retSize);
    if(ret1==NULL) {
        printf("Can't not find...\ncount=%d\n", cnt);
    } else {

        for(int i=0; i<size; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        for(int i=0; i<retSize; i++) {
            printf("ret[%d] = %d, count = %d\n", i, ret1[i], cnt);
        }
    }

    return 0;
}
