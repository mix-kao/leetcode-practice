#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BEFORE  "Before sort"
#define AFTER   "After  sort"

int unsorted_data[] = {48, 32, 4392, 2, 34, 321, 39, 89, 9, 24, 234};

void showData(int ary_num, char* prefix) {
    int i;
    printf("%s ", prefix);
    for(i=0; i<ary_num; i++) {
        printf("%4d ", unsorted_data[i]);
    }
    printf("\n");
}
/*第一個迴圈是要比幾次*/
/*執行時，未排序資料中的最大值會如同氣泡般往右跑*/
void bubble_sort(int ary_num, int* ptr) {
    int temp, count=0;
    int swap = 0;
    for(int i=ary_num-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            count++;
            if(unsorted_data[j] > unsorted_data[j+1]) {
                temp = unsorted_data[j+1];
                unsorted_data[j+1] = unsorted_data[j];
                unsorted_data[j] = temp;
                swap = 1;
            }
        }
    }
    printf("bubble sort element number = %d, time complexity = %d\n", ary_num, count);
    if(swap) printf("sorted\n");
    else printf("not sort\n");
}

/*每次最小的會被換到最前面*/
void select_sort(int ary_num, int* ptr) {
    int temp, count=0;
    int swap = 0;
    for(int i=0; i<ary_num-1; i++) {
        for(int j=i+1; j<ary_num; j++) {
            count++;
            if(unsorted_data[i] > unsorted_data[j]) {
                temp = unsorted_data[i];
                unsorted_data[i] = unsorted_data[j];
                unsorted_data[j] = temp;
                swap = 1;
            }
        }
    }
    printf("Select sort element number = %d, time complexity = %d\n", ary_num, count);
    if(swap) printf("sorted\n");
    else printf("not sort\n");
}

int main(void) {
    int ary_num = sizeof(unsorted_data)/sizeof(unsorted_data[0]);
    showData(ary_num, BEFORE);
    bubble_sort(ary_num, unsorted_data);
    select_sort(ary_num, unsorted_data);
    showData(ary_num, AFTER);
    return 0;
}
