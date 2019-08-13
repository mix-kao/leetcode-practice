#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 6

// Function for finding
// elements which are there
// in a[] but not in b[].
void findMissing(int a[], int b[], size_t a_size, size_t b_size) {
    int same_flag = 0;
    int count = 0;
    for(int i=0; i<a_size; i++) {
        same_flag = 0;
        for(int j=0; j<b_size; j++) {
            count++;
            if(a[i] == b[j]) { same_flag = 1; break;}
        }
        if(!same_flag) printf("%d\n", a[i]);
    }
    printf("count = %d\n", count);
}

void findMissing1(int* a, int* b, size_t a_size, size_t b_size) {
    int same_flag = 0;
    int count = 0;
    for(int i=0; i<a_size; i++) {
        same_flag = 0;
        for(int j=0; j<b_size; j++) {
            count++;
            if(*(a+i) == *(b+j)) { same_flag = 1; break;}
        }
        if(!same_flag) printf("%d\n", *(a+i));
    }
    printf("count = %d\n", count);

}

void findMissingByHash(int* a, int* b, size_t a_size, size_t b_size) {
    int same_flag = 0;
    int b_hash[HASH_SIZE];
    int remainder;
    int count = 0;
    memset(b_hash, -1, sizeof(b_hash));
    for(int j=0; j<b_size; j++) {
        remainder = *(b+j)%(HASH_SIZE);
        b_hash[remainder] = *(b+j);
        count++;
    }
    for(int i=0; i<a_size; i++) {
        count++;
        same_flag = 0;
        remainder = *(a+i)%HASH_SIZE;
        if(b_hash[remainder]!=-1) same_flag=1;
        if(!same_flag) printf("%d\n", *(a+i));
    }
    printf("count = %d\n", count);

}


int main(void) {
    
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};

    size_t a_size = sizeof(a)/sizeof(a[0]);
    size_t b_size = sizeof(b)/sizeof(b[0]);

    findMissing(a, b, a_size, b_size);
    findMissing1(a, b, a_size, b_size);
    findMissingByHash(a, b, a_size, b_size);

    return 0;
}
